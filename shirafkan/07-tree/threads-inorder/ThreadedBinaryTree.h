#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H

#include <iostream>

class ThreadedBinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        bool rflag;   // true if right is a thread

        Node(int val)
            : data(val), left(nullptr), right(nullptr), rflag(false) {}
    };

    Node* root;

    Node* leftmost(Node* n) const;

public:
    ThreadedBinaryTree();
    ~ThreadedBinaryTree();

    // disable copying
    ThreadedBinaryTree(const ThreadedBinaryTree&) = delete;
    ThreadedBinaryTree& operator=(const ThreadedBinaryTree&) = delete;

    // allow adding children manually
    Node* createNode(int value);
    Node* getRoot() const;

    void setRoot(Node* r);
    void inorder() const;

    // recursive deletion (ignores threads)
    void clear(Node* n);
};

#endif
