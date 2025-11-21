#include "Ancestors.h"

int main() {

    // Construct tree
    auto root = create(6);
    root->left = create(2);
    root->right = create(3);

    root->left->left = create(7);
    root->left->right = create(5);

    root->left->left->right = create(8);

    // Find ancestors of 3
    ancestors(root.get(), 3);

    return 0;
}
