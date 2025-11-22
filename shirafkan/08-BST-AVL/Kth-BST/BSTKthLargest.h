#ifndef BST_KTH_LARGEST_H
#define BST_KTH_LARGEST_H

#include <iostream>

// ---------------------------
// Node definition
// ---------------------------
struct Node {
    int data{};
    Node* left{};
    Node* right{};

    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ---------------------------
// BST operations
// ---------------------------
Node* insert(Node* root, int value);

// Find k-th largest
void kthLargestHelper(Node* root, int k, int& counter);
void kthLargest(Node* root, int k);

// Utility
void freeTree(Node* root);

#endif
