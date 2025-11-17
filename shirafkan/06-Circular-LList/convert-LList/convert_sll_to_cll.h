#ifndef CONVERT_SLL_TO_CLL_H
#define CONVERT_SLL_TO_CLL_H

#include <iostream>

class SinglyList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    SinglyList();
    ~SinglyList();

    void push_front(int value);
    void convert_to_circular();
    void print() const;

    bool is_empty() const { return head == nullptr; }
};

#endif
