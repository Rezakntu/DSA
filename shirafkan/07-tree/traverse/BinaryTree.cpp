#include "BinaryTree.h"

std::unique_ptr<BinaryTree::Node> BinaryTree::create(int value) {
    return std::make_unique<Node>(value);
}

void BinaryTree::preorder(const std::unique_ptr<Node>& p) const {
    if (!p) return;

    std::cout << p->data << " ";
    preorder(p->left);
    preorder(p->right);
}

void BinaryTree::inorder(const std::unique_ptr<Node>& p) const {
    if (!p) return;

    inorder(p->left);
    std::cout << p->data << " ";
    inorder(p->right);
}

void BinaryTree::postorder(const std::unique_ptr<Node>& p) const {
    if (!p) return;

    postorder(p->left);
    postorder(p->right);
    std::cout << p->data << " ";
}
