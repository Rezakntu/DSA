#include "BinaryTree.h"

int main() {
  BinaryTree tree;

  auto root = tree.create(1);

  root->left  = tree.create(2);
  root->right = tree.create(3);

  root->left->left  = tree.create(4);
  root->left->right = tree.create(5);

  tree.inorderNonRecursive(root);   // Output: 4 2 5 1 3

  std::cout << std::endl;
  return 0;
}
