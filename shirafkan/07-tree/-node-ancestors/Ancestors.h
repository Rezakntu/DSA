#ifndef ANCESTORS_H
#define ANCESTORS_H

#include <memory>
#include <iostream>

class Node {
public:
    int data{};
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int value);
};

std::unique_ptr<Node> create(int value);
bool ancestors(const Node* root, int target);

#endif
