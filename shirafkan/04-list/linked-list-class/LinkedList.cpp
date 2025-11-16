#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

// Node constructor
LinkedList::Node::Node(int d) : data(d), next(nullptr) {}

// Default constructor
LinkedList::LinkedList() : head(nullptr) {}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other) {
    head = clone_list(other.head);
}

// Copy assignment
LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this != &other) {
        head = clone_list(other.head);
    }
    return *this;
}

// Add at beginning
void LinkedList::add_begin(int value) {
    auto n = std::make_unique<Node>(value);
    n->next = std::move(head);
    head = std::move(n);
}

// Display list
void LinkedList::show() const {
    const Node* curr = head.get();
    while (curr) {
        std::cout << curr->data << " -> ";
        curr = curr->next.get();
    }
    std::cout << "NULL\n";
}

// Delete all occurrences of a value
void LinkedList::delete_all(int value) {
    while (head && head->data == value) {
        head = std::move(head->next);
    }

    Node* curr = head.get();
    while (curr && curr->next) {
        if (curr->next->data == value) {
            curr->next = std::move(curr->next->next);
        } else {
            curr = curr->next.get();
        }
    }
}

// Find k-th node (1-indexed)
int LinkedList::find_kth(int k) const {
    const Node* curr = head.get();
    int idx = 1;

    while (curr) {
        if (idx == k) return curr->data;
        curr = curr->next.get();
        idx++;
    }
    throw std::out_of_range("k is larger than list length");
}

// Middle element
int LinkedList::middle() const {
    const Node* slow = head.get();
    const Node* fast = head.get();

    while (fast && fast->next) {
        slow = slow->next.get();
        fast = fast->next->next.get();
    }

    if (!slow) throw std::runtime_error("List is empty");
    return slow->data;
}

// Concatenate two lists
void LinkedList::concat(LinkedList& other) {
    if (!head) {
        head = std::move(other.head);
        return;
    }

    Node* curr = head.get();
    while (curr->next) curr = curr->next.get();

    curr->next = std::move(other.head);
}

// Length of list
int LinkedList::length() const {
    int count = 0;
    const Node* curr = head.get();
    while (curr) {
        count++;
        curr = curr->next.get();
    }
    return count;
}

// Add zeros at front
void LinkedList::pad_zeros(int n) {
    while (n--) add_begin(0);
}

// Subtraction wrapper
LinkedList LinkedList::subtract(const LinkedList& a, const LinkedList& b) {
    LinkedList A = a;
    LinkedList B = b;

    int lenA = A.length();
    int lenB = B.length();

    if (lenA > lenB) B.pad_zeros(lenA - lenB);
    else if (lenB > lenA) A.pad_zeros(lenB - lenA);

    bool borrow = false;

    LinkedList result;
    result.head = subtract_recursive(A.head.get(), B.head.get(), borrow);
    return result;
}

// Recursive subtract helper
std::unique_ptr<LinkedList::Node>
LinkedList::subtract_recursive(const Node* n1, const Node* n2, bool& borrow)
{
    if (!n1 && !n2) return nullptr;

    auto nextNode = subtract_recursive(
        n1->next.get(),
        n2->next.get(),
        borrow
    );

    int d1 = n1->data;
    int d2 = n2->data;

    if (borrow) {
        d1--;
        borrow = false;
    }
    if (d1 < d2) {
        d1 += 10;
        borrow = true;
    }

    auto curr = std::make_unique<Node>(d1 - d2);
    curr->next = std::move(nextNode);
    return curr;
}

// Clone a list (deep copy)
std::unique_ptr<LinkedList::Node>
LinkedList::clone_list(const std::unique_ptr<Node>& src)
{
    if (!src) return nullptr;

    auto newNode = std::make_unique<Node>(src->data);
    newNode->next = clone_list(src->next);
    return newNode;
}
