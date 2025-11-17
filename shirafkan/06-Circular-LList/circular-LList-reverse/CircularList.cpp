#include "CircularList.h"

CircularList::CircularList() : head(nullptr) {}

CircularList::~CircularList() {
    if (!head) return;

    Node* curr = head->next;

    // Break circularity to delete safely
    head->next = nullptr;

    while (curr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }

    delete head;
}

void CircularList::push_back(int value) {
    Node* n = new Node(value);

    if (!head) {
        head = n;
        n->next = n;   // circular
        return;
    }

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = n;
    n->next = head;
}

void CircularList::reverse() {
    if (!head || head->next == head)
        return;

    Node *prev = nullptr, *curr = head, *next = nullptr;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

void CircularList::print() const {
    if (!head) {
        std::cout << "Empty\n";
        return;
    }

    Node* t = head;
    do {
        std::cout << t->data << " ";
        t = t->next;
    } while (t != head);

    std::cout << "\n";
}
