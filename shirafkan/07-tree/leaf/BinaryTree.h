#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>

class BinaryTree {
private:
    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int value) : data(value) {}
    };

    std::unique_ptr<Node> root;

    unsigned int countLeaves(const Node* node) const;

public:
    BinaryTree() = default;

    void setRoot(int value);
    Node* getRoot() const { return root.get(); }

    Node* addLeft(Node* parent, int value);
    Node* addRight(Node* parent, int value);

    unsigned int countLeaves() const;         // leaves in entire tree
    unsigned int countLeaves(Node* node) const; // leaves in subtree
};

#endif
