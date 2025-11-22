#include "BST.h"

// ---------------- Node ----------------
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

// ---------------- BST -----------------
BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

// Recursively free memory
void BST::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Public insert
void BST::insert(int value) {
    root = insert(root, value);
}

// Private insert (recursive)
Node* BST::insert(Node* node, int value) {
    if (!node)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;   // unchanged if equal
}

// Public inorder
void BST::inorder() const {
    inorder(root);
    std::cout << "\n";
}

// Private inorder recursion
void BST::inorder(Node* node) const {
    if (!node) return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}
