#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    tree.setRoot(1);
    auto r = tree.getRoot();

    auto n2 = tree.addLeft(r, 2);
    auto n3 = tree.addRight(r, 3);

    tree.addLeft(n2, 4);
    auto n5 = tree.addRight(n2, 5);

    tree.addLeft(n5, 6);

    std::cout << tree.countLeaves();

    return 0;
}
