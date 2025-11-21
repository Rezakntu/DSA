#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
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

    void preorder (const std::unique_ptr<Node>& p) const;
    void inorder  (const std::unique_ptr<Node>& p) const;
    void postorder(const std::unique_ptr<Node>& p) const;
};

#endif
