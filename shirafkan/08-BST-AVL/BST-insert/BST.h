#ifndef BST_H
#define BST_H

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    explicit Node(int value);
};

class BST {
public:
    BST();
    ~BST();

    void insert(int value);
    void inorder() const;

private:
    Node* root;

    Node* insert(Node* node, int value);
    void inorder(Node* node) const;
    void destroy(Node* node);
};

#endif // BST_H
