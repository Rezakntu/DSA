#include "DoublyLinkedList.h"

// ============================================================
// addFirst
// ============================================================
void DoublyLinkedList::addFirst(int value)
{
    auto newNode = std::make_unique<Node>(value);
    newNode->next = std::move(head);

    if (newNode->next)
        newNode->next->prev = newNode.get();

    head = std::move(newNode);
}

// ============================================================
// addLast
// ============================================================
void DoublyLinkedList::addLast(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        head = std::move(newNode);
        return;
    }

    Node* current = head.get();
    while (current->next)
        current = current->next.get();

    newNode->prev = current;
    current->next = std::move(newNode);
}

// ============================================================
// addAfter
// ============================================================
void DoublyLinkedList::addAfter(Node* p, int value)
{
    if (!p)
        return;

    auto newNode = std::make_unique<Node>(value);

    // Step 1: Connect newNode forward
    newNode->next = std::move(p->next);
    if (newNode->next)
        newNode->next->prev = newNode.get();

    // Step 2: Connect p to newNode
    newNode->prev = p;
    p->next = std::move(newNode);
}

// ============================================================
// show
// ============================================================
void DoublyLinkedList::show() const
{
    Node* cur = head.get();
    while (cur) {
        std::cout << cur->data << " -> ";
        cur = cur->next.get();
    }
    std::cout << "NULL\n";
}
