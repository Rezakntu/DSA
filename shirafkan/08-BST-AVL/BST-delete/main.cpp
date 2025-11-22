#include "BST.h"

int main() {
    BST tree;
    Node* root = nullptr;

    /*
               5
            /     \
           3       8
         /  \    /   \
        2   4   7     9
               /
              6
    */

    root = tree.insert(root, 5);
    tree.insert(root, 3);
    tree.insert(root, 8);
    tree.insert(root, 4);
    tree.insert(root, 7);
    tree.insert(root, 2);
    tree.insert(root, 9);
    tree.insert(root, 6);

    tree.inorder(root);
    std::cout << "\n\n";

    root = tree.removeNode(root, 5);

    tree.inorder(root);
    std::cout << "\n";

    return 0;
}
