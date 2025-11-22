#include "BST.h"

//--------------------------------------------
// Node constructor
//--------------------------------------------
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}


//--------------------------------------------
// Insert a value into the BST
//--------------------------------------------
Node* BST::insert(Node* root, int value) {
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


//--------------------------------------------
// Inorder traversal
//--------------------------------------------
void BST::inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}


//--------------------------------------------
// Find the minimum node (inorder successor)
//--------------------------------------------
Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}


//--------------------------------------------
// Delete a node from BST
//--------------------------------------------
Node* BST::removeNode(Node* root, int key) {
    if (!root)
        return nullptr;

    if (key < root->data) {
        root->left = removeNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = removeNode(root->right, key);
    }
    else {
        // node found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;

        root->right = removeNode(root->right, temp->data);
    }

    return root;
}
