#ifndef TREE_H
#define TREE_H

#include <memory>
#include <iostream>

class Node {
public:
    int data{};
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int value);

    // Factory
    static std::unique_ptr<Node> create(int value);
};

// Compare two trees for equality
bool identical(const std::unique_ptr<Node>& a,
               const std::unique_ptr<Node>& b);

#endif
