#include "BinaryTree.h"

// Initialize root
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

unsigned int BinaryTree::countLeaves(const Node* node) const {
    if (!node)
        return 0;

    // Leaf node
    if (!node->left && !node->right)
        return 1;

    return countLeaves(node->left.get()) + countLeaves(node->right.get());
}

unsigned int BinaryTree::countLeaves() const {
    return countLeaves(root.get());
}

unsigned int BinaryTree::countLeaves(Node* node) const {
    return countLeaves(static_cast<const Node*>(node));
}
