#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

class AVLTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int item)
            : data(item), left(nullptr), right(nullptr), height(1) {}
    };

    AVLTree();
    ~AVLTree();

    void insert(int key);
    void preorder() const;

private:
    Node* root;

    // internal helpers
    Node* insert(Node* node, int key);
    Node* leftRotate(Node* x);
    Node* rightRotate(Node* y);
    int height(Node* node) const;
    int balanceFactor(Node* node) const;
    int max(int a, int b) const;

    void preorder(Node* node) const;
    void destroy(Node* node);
};

#endif
