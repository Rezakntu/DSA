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

        Node(int value) : data(value) {}
    };

private:
    std::unique_ptr<Node> head;

public:
    DoublyLinkedList() = default;

    Node* head_ptr() const { return head.get(); }

    // Insert at beginning
    void addFirst(int value);

    // Insert at end
    void addLast(int value);

    // Insert after given node
    void addAfter(Node* p, int value);

    // Print list
    void show() const;
};

#endif
