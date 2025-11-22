#include "AVLTree.h"

// constructor
AVLTree::AVLTree() : root(nullptr) {}

// destructor
AVLTree::~AVLTree() {
    destroy(root);
}

// delete all nodes
void AVLTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// get height
int AVLTree::height(Node* node) const {
    return node ? node->height : 0;
}

// get max of two ints
int AVLTree::max(int a, int b) const {
    return (a > b) ? a : b;
}

// compute balance factor
int AVLTree::balanceFactor(Node* node) const {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

// right rotation
AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// left rotation
AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// public insert
void AVLTree::insert(int key) {
    root = insert(root, key);
}

// internal insert
AVLTree::Node* AVLTree::insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // duplicates not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left
    if (balance >= 2 && key < node->left->data)
        return rightRotate(node);

    // Right Right
    if (balance <= -2 && key > node->right->data)
        return leftRotate(node);

    // Left Right
    if (balance >= 2 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance <= -2 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// public traversal
void AVLTree::preorder() const {
    preorder(root);
    std::cout << "\n";
}

// internal preorder
void AVLTree::preorder(Node* node) const {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
