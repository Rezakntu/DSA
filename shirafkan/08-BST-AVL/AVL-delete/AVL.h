#pragma once
#include <memory>

class AVL {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        int height;
        explicit Node(int v) : data(v), left(nullptr), right(nullptr), height(1) {}
    };

    std::shared_ptr<Node> root;

    int height(const std::shared_ptr<Node>& n) const;
    int balanceFactor(const std::shared_ptr<Node>& n) const;
    void updateHeight(const std::shared_ptr<Node>& n);

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> y);
    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> x);

    std::shared_ptr<Node> insertNode(std::shared_ptr<Node> node, int key);
    std::shared_ptr<Node> minValueNode(std::shared_ptr<Node> node) const;
    std::shared_ptr<Node> removeNode(std::shared_ptr<Node> node, int key);

public:
    AVL() = default;

    void insert(int key);
    void remove(int key);
    void preorder() const;                  // prints preorder traversal
private:
    void preorderNode(const std::shared_ptr<Node>& n) const;
};
