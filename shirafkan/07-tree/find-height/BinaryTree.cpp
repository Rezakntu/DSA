#include "BinaryTree.h"

void BinaryTree::setRoot(int value) {
    root = std::make_unique<Node>(value);
}

BinaryTree::Node* BinaryTree::addLeft(Node* parent, int value) {
    parent->left = std::make_unique<Node>(value);
    return parent->left.get();
}

BinaryTree::Node* BinaryTree::addRight(Node* parent, int value) {
    parent->right = std::make_unique<Node>(value);
    return parent->right.get();
}

// Recursive height helper
int BinaryTree::height(const Node* node) const {
    if (!node)
        return -1;

    int lh = height(node->left.get());
    int rh = height(node->right.get());

    return 1 + std::max(lh, rh);
}

// Public height of full tree
int BinaryTree::height() const {
    return height(root.get());
}

// Public height of a given node
int BinaryTree::height(Node* node) const {
    return height(static_cast<const Node*>(node));
}
