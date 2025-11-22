#include <iostream>
#include "BST.h"

int main() {
    Node* r = nullptr;

    r = insert(r, 50);
    insert(r, 30);
    insert(r, 20);
    insert(r, 40);
    insert(r, 70);
    insert(r, 60);
    insert(r, 80);

    std::cout << "Searching 40: ";
    std::cout << (search(r, 40) ? "Yes" : "No") << std::endl;

    std::cout << "Inorder: ";
    inorder(r);

    return 0;
}
