#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>
#include <iostream>

class BinaryTree {
private:
    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(int value) : data(value) {}
    };

    std::unique_ptr<Node> root;

    int countNodes(const Node* node) const;

public:
    BinaryTree() = default;

    void setRoot(int value);
    Node* getRoot() const { return root.get(); }

    Node* addLeft(Node* parent, int value);
    Node* addRight(Node* parent, int value);

    int count() const;
};

#endif
