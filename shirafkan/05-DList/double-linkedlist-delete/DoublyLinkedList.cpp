#include "DoublyLinkedList.h"

// ============================================================
// create = push back
// ============================================================
void DoublyLinkedList::create(int value)
{
    auto newNode = std::make_unique<Node>(value);

    // Empty list case
    if (!head) {
        head = std::move(newNode);
        return;
    }

    Node* cur = head.get();
    while (cur->next)
        cur = cur->next.get();

    newNode->prev = cur;
    cur->next = std::move(newNode);
}

// ============================================================
// deleteNode
// ============================================================
bool DoublyLinkedList::deleteNode(int value)
{
    if (!head)
        return false;

    Node* cur = head.get();

    // ----------- CASE 1: delete head -----------
    if (cur->data == value) {
        std::unique_ptr<Node> oldHead = std::move(head);
        head = std::move(oldHead->next);
        if (head)
            head->prev = nullptr;
        return true;
    }

    // ----------- CASE 2: delete in middle / last -----------
    while (cur->next) {
        if (cur->next->data == value) {
            std::unique_ptr<Node> victim = std::move(cur->next);

            // Connect next node back to current
            if (victim->next) {
                victim->next->prev = cur;
                cur->next = std::move(victim->next);
            }
            else {
                // victim was the last node
                cur->next = nullptr;
            }
            return true;
        }
        cur = cur->next.get();
    }

    std::cout << "not found\n";
    return false;
}

// ============================================================
// show
// ============================================================
void DoublyLinkedList::show() const
{
    Node* cur = head.get();
    if (!cur) {
        std::cout << "empty\n";
        return;
    }

    while (cur) {
        std::cout << cur->data << " <-> ";
        cur = cur->next.get();
    }
    std::cout << "NULL\n";
}
