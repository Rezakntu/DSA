#include <iostream>
#include "BinaryTree.h"

int main() {
  /*
          11
        /    \
       12    13
      /     /
     14    15
  */

  auto root = BinaryTree::create(11);
  root->left  = BinaryTree::create(12);
  root->right = BinaryTree::create(13);

  root->left->left  = BinaryTree::create(14);
  root->right->left = BinaryTree::create(15);

  if (BinaryTree::isComplete(root))
    std::cout << "yes\n";
  else
    std::cout << "no\n";

  return 0;
}
