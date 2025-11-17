#include "CircularDoublyList.h"

void CircularDoublyList::addBegin(int value) {
    auto n = std::make_shared<Node>(value);
    counter++;

    if (!start) {
        // First node
        start = last = n;
        n->next = n;
        n->prev = n;
        return;
    }

    // Connect new node
    n->next = start;
    n->prev = last;

    start->prev = n;
    last->next = n;

    start = n;
}

void CircularDoublyList::addEnd(int value) {
    auto n = std::make_shared<Node>(value);
    counter++;

    if (!start) {
        start = last = n;
        n->next = n;
        n->prev = n;
        return;
    }

    n->next = start;
    n->prev = last;

    last->next = n;
    start->prev = n;

    last = n;
}

void CircularDoublyList::display() const {
    if (!start) {
        std::cout << "List is empty\n";
        return;
    }

    auto curr = start;
    for (size_t i = 0; i < counter; i++) {
        std::cout << curr->data;
        if (i < counter - 1) std::cout << " <-> ";
        curr = curr->next;
    }
    std::cout << "\n";
}
