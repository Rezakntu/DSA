#include "BST.h"

int main() {
    BST tree;

    tree.insert(8);
    tree.insert(5);
    tree.insert(30);
    tree.insert(20);
    tree.insert(9);

    tree.inorder();   // 5 8 9 20 30

    return 0;
}
