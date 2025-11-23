#include "AVL.h"
#include <iostream>

int main() {
    AVL tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    std::cout << "Preorder after inserts: ";
    tree.preorder();

    tree.remove(2);
    std::cout << "Preorder after removing 2: ";
    tree.preorder();

    return 0;
}
