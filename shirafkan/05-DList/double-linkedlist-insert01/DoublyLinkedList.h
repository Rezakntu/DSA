#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>
#include <iostream>

class DoublyLinkedList
{
public:
    struct Node {
        int data;
        std::unique_ptr<Node> next;
        std::weak_ptr<Node> prev;

        explicit Node(int d) : data(d) {}
    };

    DoublyLinkedList();
    ~DoublyLinkedList() = default;

    void push_back(int value);
    void push_front(int value);
    void insert_after(int pos, int value);

    void show() const;

private:
    std::unique_ptr<Node> head;
    std::weak_ptr<Node> tail;   // not required but convenient

    std::shared_ptr<Node> get_raw(Node* p) const;
};

#endif
