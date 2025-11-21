#include <iostream>
#include "BinaryTreeLCA.h"

int main()
{
    Node* root = createNode(1);
    root->left               = createNode(2);
    root->right              = createNode(3);
    root->left->left         = createNode(4);
    root->left->right        = createNode(5);
    root->right->left        = createNode(6);
    root->right->right       = createNode(7);
    root->left->right->right = createNode(8);

    Node* lca = findLCA(root, 4, 2);

    if (lca)
        std::cout << "LCA: " << lca->data << "\n";
    else
        std::cout << "No LCA found\n";

    return 0;
}
