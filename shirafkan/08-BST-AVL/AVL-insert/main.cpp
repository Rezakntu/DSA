#include "AVLTree.h"

int main() {
    AVLTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    tree.preorder();
}
