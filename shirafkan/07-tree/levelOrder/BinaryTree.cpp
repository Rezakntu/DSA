#include "BinaryTree.h"

std::unique_ptr<BinaryTree::Node> BinaryTree::create(int value) {
    return std::make_unique<Node>(value);
}

void BinaryTree::levelOrder(const std::unique_ptr<Node>& root) const {
    if (!root) return;

    std::queue<const Node*> q;
    q.push(root.get());

    while (!q.empty()) {
        const Node* cur = q.front();
        q.pop();

        std::cout << cur->data << "  ";

        if (cur->left)
            q.push(cur->left.get());
        if (cur->right)
            q.push(cur->right.get());
    }
}
