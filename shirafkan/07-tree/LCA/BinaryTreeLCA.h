#pragma once
#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Create new node
Node* createNode(int value);

// Find Lowest Common Ancestor (internal helper)
Node* LCA(Node* root, int a, bool& fa, int b, bool& fb);

// Search for a key in the tree
bool find(Node* root, int key);

// Public LCA wrapper
Node* findLCA(Node* root, int a, int b);

// Utility inorder traversal (optional)
void inorder(Node* root);
