#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <memory>
#include <string>
#include <iostream>

class ExpressionTree {
public:
    // Node structure (modern C++ with smart pointers)
    struct Node {
        char value{};
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(char v) noexcept : value(v) {}
    };

    // Build tree from postfix expression
    static std::unique_ptr<Node> buildFromPostfix(const std::string& postfix);

    // Print inorder traversal
    static void inorder(const Node* node) noexcept;

private:
    static bool isOperator(char c) noexcept;
};

#endif
