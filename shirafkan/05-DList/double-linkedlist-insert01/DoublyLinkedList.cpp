#include "DoublyLinkedList.h"

// push back
void DoublyLinkedList::push_back(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        tail = newNode.get();
        head = std::move(newNode);
        return;
    }

    newNode->prev = tail;
    tail->next = std::move(newNode);
    tail = tail->next.get();
}

// push front
void DoublyLinkedList::push_front(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (head) {
        newNode->next = std::move(head);
        newNode->next->prev = newNode.get();
    } else {
        tail = newNode.get();
    }

    head = std::move(newNode);
}

// insert after index (0-based)
void DoublyLinkedList::insert_after(int pos, int value)
{
    if (!head) {
        std::cout << "List is empty\n";
        return;
    }

    Node* p = head.get();
    for (int i = 0; i < pos; i++) {
        if (!p->next) {
            std::cout << "Position out of range\n";
            return;
        }
        p = p->next.get();
    }

    auto newNode = std::make_unique<Node>(value);

    newNode->prev = p;
    newNode->next = std::move(p->next);

    if (newNode->next)
        newNode->next->prev = newNode.get();
    else
        tail = newNode.get();

    p->next = std::move(newNode);
}

// display
void DoublyLinkedList::show() const
{
    Node* p = head.get();
    while (p) {
        std::cout << p->data << " <-> ";
        p = p->next.get();
    }
    std::cout << "NULL\n";
}
