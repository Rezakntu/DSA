#ifndef JOSEPHUS_LIST_H
#define JOSEPHUS_LIST_H

#include <memory>

class JosephusList {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        Node(int value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> head;

public:
    JosephusList() = default;

    void createList(int n);
    int solve();
    bool empty() const { return !head; }
};

#endif
