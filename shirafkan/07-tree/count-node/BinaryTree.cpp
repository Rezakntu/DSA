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

int BinaryTree::countNodes(const Node* node) const {
    if (!node)
        return 0;
    return 1 + countNodes(node->left.get()) + countNodes(node->right.get());
}

int BinaryTree::count() const {
    return countNodes(root.get());
}
