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

    BinaryTree() = default;

    std::unique_ptr<Node> create(int value) {
        return std::make_unique<Node>(value);
    }

    int sumRootToLeafNumbers(const std::unique_ptr<Node>& p) const;

private:
    int tps(const std::unique_ptr<Node>& p, int current) const;
};

#endif
