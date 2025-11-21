#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    auto r = tree.create(1);

    r->left  = tree.create(2);
    r->right = tree.create(3);

    r->left->left  = tree.create(4);
    r->left->right = tree.create(5);

    r->left->right->left = tree.create(6);

    tree.levelOrder(r);

    return 0;
}
