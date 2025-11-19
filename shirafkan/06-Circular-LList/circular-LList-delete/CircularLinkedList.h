#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* last; // Pointer to last node (tail)

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void push_back(int value);   // add item at end
    void remove(int value);      // delete first occurrence
    void print() const;          // display entire list
    bool empty() const;
};

#endif
