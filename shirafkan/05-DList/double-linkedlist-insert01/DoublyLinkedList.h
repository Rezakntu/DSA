#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>
#include <iostream>

class DoublyLinkedList
{
public:
    struct Node {
        int data{};
        std::unique_ptr<Node> next;
        Node* prev = nullptr;

        explicit Node(int d) : data(d) {}
    };

    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    void push_back(int value);
    void push_front(int value);
    void insert_after(int pos, int value);

    void show() const;

private:
    std::unique_ptr<Node> head;
    Node* tail = nullptr;
};

#endif
