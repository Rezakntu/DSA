#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    auto root = tree.create(1);
    root->left  = tree.create(2);
    root->right = tree.create(3);

    root->left->left  = tree.create(4);
    root->left->right = tree.create(5);

    root->left->right->left = tree.create(6);

    tree.deleteTree(root);  // automatically deletes entire tree

    return 0;
}
