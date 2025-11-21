#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    auto root = tree.create(1);

    root->left  = tree.create(2);
    root->right = tree.create(3);

    root->left->left  = tree.create(4);
    root->left->right = tree.create(5);

    root->left->right->left = tree.create(6);

    std::cout << "preorder  : ";
    tree.preorder(root);     // 1 2 4 5 6 3

    std::cout << "\ninorder   : ";
    tree.inorder(root);      // 4 2 6 5 1 3

    std::cout << "\npostorder : ";
    tree.postorder(root);    // 4 6 5 2 3 1

    std::cout << std::endl;
    return 0;
}
