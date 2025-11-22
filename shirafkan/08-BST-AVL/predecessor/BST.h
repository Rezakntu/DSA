#ifndef BST_H
#define BST_H

#include <memory>
#include <optional>

class BST {
public:
    struct Node {
        int data{};
        std::unique_ptr<Node> left{};
        std::unique_ptr<Node> right{};

        explicit Node(int val) : data(val) {}
    };

    void insert(int value);
    std::optional<int> predecessor(int key);
    std::optional<int> successor(int key);

private:
    std::unique_ptr<Node> root{};

    void insert(std::unique_ptr<Node>& node, int value);
    void findPreSuc(Node* node, Node*& pre, Node*& suc, int key);
};

#endif
