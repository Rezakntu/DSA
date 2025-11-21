#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include <iostream>
#include <queue>

class BinaryTree {
public:
    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int value) : data(value) {}
    };

    std::unique_ptr<Node> create(int value);

    void levelOrder(const std::unique_ptr<Node>& root) const;
};

#endif
