#ifndef CIRCULAR_DOUBLY_LIST_H
#define CIRCULAR_DOUBLY_LIST_H

#include <memory>
#include <iostream>

class CircularDoublyList {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(int value) : data(value) {}
    };

    std::shared_ptr<Node> start;
    std::shared_ptr<Node> last;
    size_t counter = 0;

public:
    CircularDoublyList() = default;

    void addBegin(int value);
    void addEnd(int value);
    void display() const;
    bool empty() const { return !start; }
};

#endif
