#include "FibonacciHeap.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

// ------------------------ ctor/dtor/move ------------------------
FibonacciHeap::FibonacciHeap() : min_(nullptr), n_(0) {}

FibonacciHeap::~FibonacciHeap() {
    delete_all_roots();
}

FibonacciHeap::FibonacciHeap(FibonacciHeap&& other) noexcept
    : min_(other.min_), n_(other.n_) {
    other.min_ = nullptr;
    other.n_ = 0;
}

FibonacciHeap& FibonacciHeap::operator=(FibonacciHeap&& other) noexcept {
    if (this != &other) {
        delete_all_roots();
        min_ = other.min_;
        n_ = other.n_;
        other.min_ = nullptr;
        other.n_ = 0;
    }
    return *this;
}

// ------------------------ ring helpers ------------------------
void FibonacciHeap::insert_into_root_list(Node*& root, Node* node) {
    if (!root) {
        root = node;
        node->left = node->right = node;
    } else {
        // insert node before root (so root remains valid)
        node->right = root;
        node->left = root->left;
        root->left->right = node;
        root->left = node;
    }
}

void FibonacciHeap::remove_from_ring(Node* node) {
    if (!node) return;
    if (node->right == node) {
        // single
        node->left = node->right = node;
        return;
    }
    node->left->right = node->right;
    node->right->left = node->left;
    node->left = node->right = node;
}

// ------------------------ public API ------------------------
FibonacciHeap::Node* FibonacciHeap::insert(int key) {
    Node* x = new Node(key);
    insert_into_root_list(min_, x);
    if (!min_ || x->key < min_->key) min_ = x;
    ++n_;
    return x;
}

FibonacciHeap::Node* FibonacciHeap::minimum() const noexcept {
    return min_;
}

bool FibonacciHeap::empty() const noexcept {
    return min_ == nullptr;
}

FibonacciHeap::Node* FibonacciHeap::merge(FibonacciHeap&& other) {
    // If other is empty, nothing to do
    if (!other.min_) return min_;
    if (!min_) {
        // take other's fields
        min_ = other.min_;
        n_ = other.n_;
        other.min_ = nullptr;
        other.n_ = 0;
        return min_;
    }
    // splice root lists (concatenate circular lists)
    Node* a = min_;
    Node* b = other.min_;
    // connect a.left <-> b.left swapping edges
    Node* a_left = a->left;
    Node* b_left = b->left;
    a->left = b_left;
    b_left->right = a;
    b->left = a_left;
    a_left->right = b;
    // update min_
    if (b->key < a->key) min_ = b;
    n_ += other.n_;
    other.min_ = nullptr;
    other.n_ = 0;
    return min_;
}

FibonacciHeap::Node* FibonacciHeap::extract_min() {
    Node* z = min_;
    if (!z) return nullptr;

    // for each child of z, add to root list
    if (z->child) {
        Node* p = z->child;
        // iterate over children ring and move them to root list
        std::vector<Node*> children;
        Node* cur = p;
        do {
            children.push_back(cur);
            cur = cur->right;
        } while (cur != p);

        for (Node* c : children) {
            remove_from_ring(c);
            c->parent = nullptr;
            c->mark = false;
            insert_into_root_list(min_, c);
        }
        z->child = nullptr;
    }

    // remove z from root list
    if (z->right == z) {
        // z was the only node
        min_ = nullptr;
    } else {
        Node* newmin = z->right;
        remove_from_ring(z);
        min_ = newmin;
        consolidate();
    }

    --n_;
    // Note: caller receives pointer to z but should not delete it (we own nodes).
    // We will delete z here to keep ownership consistent.
    // However many API patterns return the key only; we'll return pointer for compatibility but delete it.
    int key = z->key;
    delete z;
    // We can't return deleted pointer; return nullptr and let user call minimum() to see new min
    (void)key;
    return min_;
}

void FibonacciHeap::decrease_key(Node* x, int new_key) {
    if (!x) throw std::invalid_argument("decrease_key: x is null");
    if (new_key > x->key) throw std::invalid_argument("new key is greater than current key");
    x->key = new_key;
    Node* y = x->parent;
    if (y && x->key < y->key) {
        cut(x, y);
        cascading_cut(y);
    }
    if (x->key < min_->key) min_ = x;
}

void FibonacciHeap::delete_key(Node* x) {
    if (!x) return;
    decrease_key(x, std::numeric_limits<int>::min());
    // extract_min will delete the min node, which is x after decrease_key
    extract_min();
}

// ------------------------ internal operations ------------------------
void FibonacciHeap::link(Node* y, Node* x) {
    // remove y from root list
    remove_from_ring(y);
    // make y a child of x
    if (!x->child) {
        x->child = y;
        y->left = y->right = y;
    } else {
        // insert y into child's ring
        Node* c = x->child;
        y->right = c;
        y->left = c->left;
        c->left->right = y;
        c->left = y;
    }
    y->parent = x;
    ++x->degree;
    y->mark = false;
}

void FibonacciHeap::consolidate() {
    if (!min_) return;
    size_t D = max_degree(n_);
    std::vector<Node*> A(D, nullptr);

    // Build a vector of root nodes to iterate (since we'll modify root list)
    std::vector<Node*> roots;
    Node* start = min_;
    Node* cur = start;
    do {
        roots.push_back(cur);
        cur = cur->right;
    } while (cur != start);

    for (Node* w : roots) {
        Node* x = w;
        size_t d = x->degree;
        while (d < A.size() && A[d]) {
            Node* y = A[d];
            if (x->key > y->key) std::swap(x, y);
            // link y under x
            link(y, x);
            A[d] = nullptr;
            ++d;
        }
        if (d >= A.size()) A.resize(d + 2, nullptr);
        A[d] = x;
    }

    // rebuild root list and find new min
    min_ = nullptr;
    for (Node* node : A) {
        if (node) {
            node->left = node->right = node;
            node->parent = nullptr;
            node->mark = false;
            if (!min_) {
                min_ = node;
            } else {
                insert_into_root_list(min_, node);
                if (node->key < min_->key) min_ = node;
            }
        }
    }
}

void FibonacciHeap::cut(Node* x, Node* y) {
    // remove x from y's child list
    if (!y || !x) return;
    if (y->child == x) {
        if (x->right == x) y->child = nullptr;
        else y->child = x->right;
    }
    remove_from_ring(x);
    --y->degree;
    // add x to root list
    x->parent = nullptr;
    x->mark = false;
    insert_into_root_list(min_, x);
}

void FibonacciHeap::cascading_cut(Node* y) {
    Node* z = y->parent;
    if (z) {
        if (!y->mark) {
            y->mark = true;
        } else {
            cut(y, z);
            cascading_cut(z);
        }
    }
}

// ------------------------ destructor helpers ------------------------
void FibonacciHeap::delete_all_roots() {
    if (!min_) return;
    // collect root list nodes
    std::vector<Node*> roots;
    Node* cur = min_;
    do {
        roots.push_back(cur);
        cur = cur->right;
    } while (cur != min_);

    // delete each root's entire tree
    for (Node* r : roots) {
        delete_subtree(r);
    }
    min_ = nullptr;
    n_ = 0;
}

void FibonacciHeap::delete_subtree(Node* root) {
    if (!root) return;
    // traverse children ring and recursively delete
    // detach root ring to avoid revisiting
    remove_from_ring(root);
    // delete descendants
    std::vector<Node*> stack;
    // push root and its children
    stack.push_back(root);
    while (!stack.empty()) {
        Node* node = stack.back();
        stack.pop_back();
        // push children of node (if any)
        if (node->child) {
            Node* c = node->child;
            Node* cur = c;
            do {
                Node* next = cur->right;
                // detach child ring
                remove_from_ring(cur);
                stack.push_back(cur);
                cur = next;
            } while (cur != c);
        }
        // finally delete node
        delete node;
    }
}
