#include "BST.h"

// Create node
Node* create(int item) {
    return new Node(item);
}

// Recursive search
Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key)
        return root;

    if (key > root->data)
        return searchRecursive(root->right, key);

    return searchRecursive(root->left, key);
}

// Iterative search
bool search(Node* root, int key) {
    while (root) {
        if (key == root->data)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// Insert key
Node* insert(Node* root, int item) {
    if (!root)
        return create(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else if (item > root->data)
        root->right = insert(root->right, item);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
