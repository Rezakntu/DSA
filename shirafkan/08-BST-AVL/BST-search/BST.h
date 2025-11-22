#pragma once
#include <iostream>

// A simple Binary Search Tree using raw pointers (close to original logic)
struct Node {
    int data{};
    Node* left{nullptr};
    Node* right{nullptr};

    Node(int value) : data(value) {}
};

// Create a new node
Node* create(int item);

// Search recursively
Node* searchRecursive(Node* root, int key);

// Search iteratively
bool search(Node* root, int key);

// Insert a key
Node* insert(Node* root, int item);

// Inorder traversal
void inorder(Node* root);

