#include "BinaryTreeLCA.h"

// Create new node
Node* createNode(int value)
{
    return new Node(value);
}

// Recursive LCA computation.
// fa/fb mark whether a and b have been found.
Node* LCA(Node* root, int a, bool& fa, int b, bool& fb)
{
    if (!root) return nullptr;

    if (root->data == a) { fa = true; return root; }
    if (root->data == b) { fb = true; return root; }

    Node* leftLca  = LCA(root->left,  a, fa, b, fb);
    Node* rightLca = LCA(root->right, a, fa, b, fb);

    if (leftLca && rightLca)
        return root;

    return leftLca ? leftLca : rightLca;
}

// Search for a value in the tree
bool find(Node* root, int key)
{
    if (!root) return false;
    return (root->data == key) || find(root->left, key) || find(root->right, key);
}

// Public LCA wrapper
Node* findLCA(Node* root, int a, int b)
{
    bool fa = false, fb = false;

    Node* result = LCA(root, a, fa, b, fb);

    // Validate result:
    // If both found inside recursion OR one found earlier and the other exists under result.
    if ((fa && fb) || (fa && find(result, b)) || (fb && find(result, a)))
        return result;

    return nullptr;
}

// Optional inorder traversal
void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
