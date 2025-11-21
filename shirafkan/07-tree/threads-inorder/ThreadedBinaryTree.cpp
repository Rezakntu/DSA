#include "ThreadedBinaryTree.h"

ThreadedBinaryTree::ThreadedBinaryTree() : root(nullptr) {}

ThreadedBinaryTree::~ThreadedBinaryTree() {
    clear(root);
}

void ThreadedBinaryTree::clear(Node* n) {
    if (!n || n->rflag) return; // do not follow threaded pointers

    clear(n->left);
    clear(n->right);
    delete n;
}

ThreadedBinaryTree::Node* ThreadedBinaryTree::createNode(int value) {
    return new Node(value);
}

void ThreadedBinaryTree::setRoot(Node* r) {
    root = r;
}

ThreadedBinaryTree::Node* ThreadedBinaryTree::getRoot() const {
    return root;
}

ThreadedBinaryTree::Node* ThreadedBinaryTree::leftmost(Node* n) const {
    if (!n) return nullptr;

    while (n->left)
        n = n->left;

    return n;
}

void ThreadedBinaryTree::inorder() const {
    Node* cur = leftmost(root);

    while (cur) {
        std::cout << cur->data << " ";

        if (cur->rflag)
            cur = cur->right;            // follow thread
        else
            cur = leftmost(cur->right);  // go to leftmost in right subtree
    }
}
