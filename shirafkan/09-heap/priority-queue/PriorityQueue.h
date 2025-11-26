#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <memory>
#include <iostream>

class PriorityQueue {
private:
    struct Node {
        int data;
        int priority;
        std::unique_ptr<Node> next;

        Node(int d, int p) : data(d), priority(p), next(nullptr) {}
    };

    std::unique_ptr<Node> front;     // pointer to highest priority node

public:
    PriorityQueue();

    void push(int value, int priority);  // insert
    void pop();                          // remove highest priority
    bool empty() const;
    void display() const;
};

#endif
