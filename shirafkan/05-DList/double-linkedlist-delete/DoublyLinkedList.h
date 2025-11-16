#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>
#include <iostream>

class DoublyLinkedList {
public:
    struct Node {
        int data{};
        std::unique_ptr<Node> next{};
        Node* prev = nullptr;

        explicit Node(int value) : data(value) {}
    };

private:
    std::unique_ptr<Node> head;

public:
    DoublyLinkedList() = default;

    Node* head_ptr() const { return head.get(); }

    void create(int value);
    bool deleteNode(int value);
    void show() const;
};

#endif
