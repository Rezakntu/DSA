#include "BinaryTree.h"
#include <queue>

BinaryTree::Node::Node(int value) : data(value) {}

std::unique_ptr<BinaryTree::Node> BinaryTree::create(int value) {
    return std::make_unique<Node>(value);
}

bool BinaryTree::isComplete(const std::unique_ptr<Node>& root) {
    if (!root)
        return true;

    std::queue<const Node*> q;
    q.push(root.get());

    bool missingChildFound = false;

    while (!q.empty()) {
        const Node* curr = q.front();
        q.pop();

        // Check left child
        if (curr->left) {
            if (missingChildFound)
                return false;
            q.push(curr->left.get());
        } else {
            missingChildFound = true;
        }

        // Check right child
        if (curr->right) {
            if (missingChildFound)
                return false;
            q.push(curr->right.get());
        } else {
            missingChildFound = true;
        }
    }

    return true;
}
