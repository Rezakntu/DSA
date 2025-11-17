#include "CircularList.h"

CircularList::CircularList() : head(nullptr) {}

CircularList::~CircularList() {
    if (!head) return;

    Node* curr = head->next;

    // Break the circular chain for safe deletion
    head->next = nullptr;

    // Now delete as a normal list
    while (curr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }

    delete head;
}

void CircularList::push_front(int value) {
    Node* n = new Node(value);

    if (!head) {
        head = n;
        n->next = head;   // circular
        return;
    }

    // Insert before head (front)
    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    n->next = head;
    tail->next = n;
    head = n;
}

int CircularList::count() const {
    if (!head) return 0;

    int c = 1;
    Node* t = head->next;

    while (t != head) {
        c++;
        t = t->next;
    }

    return c;
}

void CircularList::print() const {
    if (!head) {
        std::cout << "List empty\n";
        return;
    }

    Node* t = head;
    do {
        std::cout << t->data << " ";
        t = t->next;
    } while (t != head);

    std::cout << "\n";
}
