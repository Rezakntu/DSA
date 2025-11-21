#include "Ancestors.h"

Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

std::unique_ptr<Node> create(int value) {
    return std::make_unique<Node>(value);
}

bool ancestors(const Node* root, int target) {
    if (!root) return false;

    if (root->data == target)
        return true;

    if (ancestors(root->left.get(), target) || ancestors(root->right.get(), target)) {
        std::cout << root->data << " ";
        return true;
    }

    return false;
}
