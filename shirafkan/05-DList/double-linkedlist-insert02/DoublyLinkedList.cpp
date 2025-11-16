#include "DoublyLinkedList.h"

// Insert at beginning
void DoublyLinkedList::add_first(int value)
{
    auto newNode = std::make_unique<Node>(value);

    newNode->next = std::move(head);
    newNode->prev = nullptr;

    if (newNode->next)
        newNode->next->prev = newNode.get();

    head = std::move(newNode);
}

// Insert after a given node
void DoublyLinkedList::add_after(Node* p, int value)
{
    if (!p) return;

    auto newNode = std::make_unique<Node>(value);

    newNode->prev = p;
    newNode->next = std::move(p->next);   // steal ownership

    if (newNode->next)
        newNode->next->prev = newNode.get();

    p->next = std::move(newNode);
}

// Display
void DoublyLinkedList::show() const
{
    Node* k = head.get();
    while (k) {
        std::cout << k->data << " -> ";
        k = k->next.get();
    }
    std::cout << "NULL\n";
}
