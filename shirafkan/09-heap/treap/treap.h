#ifndef TREAP_H
#define TREAP_H

#include <memory>
#include <iostream>

class Treap
{
private:
    struct Node
    {
        int key;
        int priority;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int k)
            : key(k), priority(rand()), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    // Internal helpers
    void rotateLeft(std::unique_ptr<Node>& t);
    void rotateRight(std::unique_ptr<Node>& t);

    void insert(std::unique_ptr<Node>& t, int key);
    void remove(std::unique_ptr<Node>& t, int key);
    bool find(const std::unique_ptr<Node>& t, int key) const;

    void inorder(const std::unique_ptr<Node>& t) const;
    void display(const std::unique_ptr<Node>& t, int level) const;

public:
    Treap();

    void insert(int key);
    void remove(int key);
    bool find(int key) const;

    void inorder() const;
    void display() const;
};

#endif
