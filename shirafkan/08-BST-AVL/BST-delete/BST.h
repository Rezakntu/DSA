#pragma once
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
    Node* insert(Node* root, int value);
    Node* removeNode(Node* root, int key);
    Node* minValueNode(Node* node);
    void inorder(Node* root);
};
