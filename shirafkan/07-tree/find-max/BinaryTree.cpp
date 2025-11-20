#include "BinaryTree.h"

int BinaryTree::findMax(const std::unique_ptr<Node>& p) const {
    if (!p)
        return INT_MIN;

    int m = p->data;
    int lmax = findMax(p->left);
    int rmax = findMax(p->right);

    if (lmax > m) m = lmax;
    if (rmax > m) m = rmax;

    return m;
}
