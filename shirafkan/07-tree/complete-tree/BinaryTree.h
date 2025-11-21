#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>

class BinaryTree {
public:
    struct Node {
        int data{};
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int value);
    };

    static std::unique_ptr<Node> create(int value);

    // Returns true if the binary tree rooted at 'root' is complete
    static bool isComplete(const std::unique_ptr<Node>& root);
};

#endif
