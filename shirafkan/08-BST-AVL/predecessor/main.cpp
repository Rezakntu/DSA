#include "BST.h"
#include <iostream>

int main() {
    /*
               5
            /     \
           3       7
          / \     /  \
        2    4   6    8
    */

    BST tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);

    int key = 7;

    auto pre = tree.predecessor(key);
    auto suc = tree.successor(key);

    if (pre)
        std::cout << "Predecessor: " << *pre << "\n";
    else
        std::cout << "No Predecessor\n";

    if (suc)
        std::cout << "Successor: " << *suc << "\n";
    else
        std::cout << "No Successor\n";
}
