#include "DoublyLinkedList.h"

// Convert raw Node* into shared_ptr to access prev()
std::shared_ptr<DoublyLinkedList::Node>
DoublyLinkedList::get_raw(Node* p) const
{
    return p ? std::shared_ptr<Node>(head.get(), p) : nullptr;
}

// Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

// Add element at end
void DoublyLinkedList::push_back(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        head = std::move(newNode);
        tail = get_raw(head.get());
        return;
    }

    auto last = tail.lock();
    newNode->prev = last;
    last->next = std::move(newNode);
    tail = last->next ? get_raw(last->next.get()) : last;
}

// Add at beginning
void DoublyLinkedList::push_front(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (head) {
        newNode->next = std::move(head);
        newNode->next->prev = get_raw(newNode.get());
    }

    head = std::move(newNode);

    if (!tail.lock())
        tail = get_raw(head.get());
}

// Insert after a position (0-indexed)
void DoublyLinkedList::insert_after(int pos, int value)
{
    if (!head) {
        std::cout << "List is empty.\n";
        return;
    }

    Node* p = head.get();
    for (int i = 0; i < pos; i++) {
        p = p->next ? p->next.get() : nullptr;
        if (!p) {
            std::cout << "Position out of range.\n";
            return;
        }
    }

    auto newNode = std::make_unique<Node>(value);

    newNode->next = std::move(p->next);
    newNode->prev = get_raw(p);

    if (newNode->next)
        newNode->next->prev = get_raw(newNode.get());
    else
        tail = get_raw(newNode.get());

    p->next = std::move(newNode);
}

// Display list
void DoublyLinkedList::show() const
{
    if (!head) {
        std::cout << "EMPTY\n";
        return;
    }

    const Node* p = head.get();
    while (p) {
        std::cout << p->data << " <-> ";
        p = p->next.get();
    }
    std::cout << "NULL\n";
}
