#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
    : front(nullptr) {}

/*
 * Insert by priority (lower number = higher priority)
 */
void PriorityQueue::push(int value, int priority) {
    auto newNode = std::make_unique<Node>(value, priority);

    if (!front || priority < front->priority) {
        newNode->next = std::move(front);
        front = std::move(newNode);
        return;
    }

    Node* current = front.get();
    while (current->next && current->next->priority <= priority) {
        current = current->next.get();
    }

    newNode->next = std::move(current->next);
    current->next = std::move(newNode);
}

/*
 * Remove highest-priority element
 */
void PriorityQueue::pop() {
    if (!front) {
        std::cout << "Underflow\n";
        return;
    }
    front = std::move(front->next);
}

bool PriorityQueue::empty() const {
    return front == nullptr;
}

void PriorityQueue::display() const {
    if (!front) {
        std::cout << "Priority Queue is empty.\n\n";
        return;
    }

    std::cout << "Item      Priority\n";
    std::cout << "------------------\n";

    const Node* curr = front.get();
    while (curr) {
        std::cout << curr->data << "          " << curr->priority << "\n";
        curr = curr->next.get();
    }
    std::cout << "\n";
}
