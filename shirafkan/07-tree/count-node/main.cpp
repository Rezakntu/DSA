#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    tree.setRoot(1);
    auto r = tree.getRoot();

    auto left  = tree.addLeft(r, 2);
    auto right = tree.addRight(r, 3);

    tree.addLeft(left, 4);
    auto lr = tree.addRight(left, 5);

    tree.addLeft(lr, 6);

    std::cout << tree.count();

    return 0;
}
