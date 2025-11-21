#include "ThreadedBinaryTree.h"

int main() {
    ThreadedBinaryTree tree;

    auto* r = tree.createNode(1);
    tree.setRoot(r);

    r->left = tree.createNode(2);
    r->right = tree.createNode(3);

    r->left->left = tree.createNode(4);
    r->left->right = tree.createNode(5);

    // No threads created in this example (rflag always false)
    tree.inorder();

    return 0;
}
