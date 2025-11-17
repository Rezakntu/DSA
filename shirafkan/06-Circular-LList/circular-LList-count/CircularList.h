#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>

class CircularList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    CircularList();
    ~CircularList();

    void push_front(int value);
    int count() const;
    void print() const;
    bool empty() const { return head == nullptr; }
};

#endif
