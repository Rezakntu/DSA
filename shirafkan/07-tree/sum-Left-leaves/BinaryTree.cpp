#include "BinaryTree.h"

bool BinaryTree::isLeaf(const std::unique_ptr<Node>& p) const {
    if (!p) return false;
    return !p->left && !p->right;
}

int BinaryTree::sumLeftLeaves(const std::unique_ptr<Node>& p) const {
    if (!p) return 0;

    int sum = 0;

    // If left child is a leaf, add its value
    if (isLeaf(p->left)) {
        sum += p->left->data;
    } else {
        // Otherwise, explore left subtree
        sum += sumLeftLeaves(p->left);
    }

    // Always explore right subtree
    sum += sumLeftLeaves(p->right);

    return sum;
}
