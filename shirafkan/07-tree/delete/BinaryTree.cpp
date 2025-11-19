#include "BinaryTree.h"

void BinaryTree::deleteTree(std::unique_ptr<Node>& p) {
    deleteHelper(p);
    p.reset();  // ensures pointer becomes null
}

void BinaryTree::deleteHelper(std::unique_ptr<Node>& p) {
    if (!p)
        return;

    std::cout << p->data << "  ";

    deleteHelper(p->right);
    deleteHelper(p->left);

    p.reset(); // deletes automatically (unique_ptr)
}
