#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <memory>

class CircularList {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        Node(int value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> head;

public:
    CircularList() = default;

    void addBegin(int value);
    size_t size() const;
    void split(CircularList &firstHalf, CircularList &secondHalf) const;
    void show() const;
    bool empty() const { return !head; }
};

#endif
