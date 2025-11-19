#include "CircularList.h"

void CircularList::addBegin(int value) {
    auto newNode = std::make_shared<Node>(value);

    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    auto temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

size_t CircularList::size() const {
    if (!head) return 0;

    size_t count = 0;
    auto temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void CircularList::split(CircularList &firstHalf, CircularList &secondHalf) const {
    if (!head) return;

    auto slow = head;
    auto fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    firstHalf.head = head;
    secondHalf.head = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

void CircularList::show() const {
    if (!head) return;

    auto temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
