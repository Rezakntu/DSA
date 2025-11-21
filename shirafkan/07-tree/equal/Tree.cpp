#include "Tree.h"

//---------------------------------------------------------
// Node implementation
//---------------------------------------------------------
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

std::unique_ptr<Node> Node::create(int value) {
    return std::make_unique<Node>(value);
}

//---------------------------------------------------------
// Check if two trees are identical
//---------------------------------------------------------
bool identical(const std::unique_ptr<Node>& a,
               const std::unique_ptr<Node>& b)
{
    if (!a && !b)
        return true;

    if (a && b)
        return (a->data == b->data &&
                identical(a->left, b->left) &&
                identical(a->right, b->right));

    return false;
}
