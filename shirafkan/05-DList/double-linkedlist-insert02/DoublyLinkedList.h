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

    void add_first(int value);
    void add_after(Node* p, int value);
    void show() const;

    Node* head_ptr() const { return head.get(); }

private:
    std::unique_ptr<Node> head;
};

#endif
