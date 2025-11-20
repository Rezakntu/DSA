#include "BinaryTree.h"

int BinaryTree::tps(const std::unique_ptr<Node>& p, int current) const {
    if (!p) return 0;

    // Build the number so far
    current = current * 10 + p->data;

    // If leaf → return the number
    if (!p->left && !p->right)
        return current;

    // Otherwise recurse left + right
    return tps(p->left, current) + tps(p->right, current);
}

int BinaryTree::sumRootToLeafNumbers(const std::unique_ptr<Node>& p) const {
    return tps(p, 0);
}
