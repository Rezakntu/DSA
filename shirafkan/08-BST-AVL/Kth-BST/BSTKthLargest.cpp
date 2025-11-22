#include "BSTKthLargest.h"

// ----------------------------------------------------
// Insert a value into BST
// ----------------------------------------------------
Node* insert(Node* root, int value) {
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// ----------------------------------------------------
// Recursive reverse inorder traversal
// ----------------------------------------------------
void kthLargestHelper(Node* root, int k, int& counter) {
    if (!root || counter >= k)
        return;

    // Visit right subtree (larger values)
    kthLargestHelper(root->right, k, counter);

    counter++;
    if (counter == k) {
        std::cout << root->data << std::endl;
        return;
    }

    // Visit left subtree
    kthLargestHelper(root->left, k, counter);
}

// ----------------------------------------------------
void kthLargest(Node* root, int k) {
    int counter = 0;
    kthLargestHelper(root, k, counter);
}

// ----------------------------------------------------
// Free full tree memory
// ----------------------------------------------------
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
