#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include <stack>
#include <iostream>

class BinaryTree {
public:
    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int value) : data(value) {}
    };

    std::unique_ptr<Node> create(int value);

    void inorderNonRecursive(const std::unique_ptr<Node>& root) const;
};

#endif
