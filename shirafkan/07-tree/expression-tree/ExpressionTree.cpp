#include "ExpressionTree.h"
#include <stack>

bool ExpressionTree::isOperator(char c) noexcept {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

std::unique_ptr<ExpressionTree::Node>
ExpressionTree::buildFromPostfix(const std::string& postfix)
{
    std::stack<std::unique_ptr<Node>> st;

    for (char c : postfix) {
        if (!isOperator(c)) {
            st.push(std::make_unique<Node>(c));
        }
        else {
            // Operator → pop two operands
            auto right = std::move(st.top()); st.pop();
            auto left  = std::move(st.top()); st.pop();

            auto node = std::make_unique<Node>(c);
            node->right = std::move(right);
            node->left  = std::move(left);

            st.push(std::move(node));
        }
    }

    return std::move(st.top());
}

void ExpressionTree::inorder(const Node* node) noexcept {
    if (!node) return;
    inorder(node->left.get());
    std::cout << node->value;
    inorder(node->right.get());
}
