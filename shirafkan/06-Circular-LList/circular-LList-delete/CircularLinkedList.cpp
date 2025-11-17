#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : last(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    if (!last) return;

    Node* curr = last->next; // first node
    Node* next;

    while (curr != last) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    delete last; // delete final node
}

bool CircularLinkedList::empty() const {
    return last == nullptr;
}

void CircularLinkedList::push_back(int value) {
    Node* n = new Node(value);

    if (!last) {
        last = n;
        n->next = n;        // circular to itself
        return;
    }

    n->next = last->next;   // new->next points to first
    last->next = n;         // old last -> new
    last = n;               // update last
}

void CircularLinkedList::remove(int value) {
    if (!last) {
        std::cout << "List is empty.\n";
        return;
    }

    Node* first = last->next;

    // Case 1: only one node
    if (last == first && last->data == value) {
        delete last;
        last = nullptr;
        return;
    }

    // Case 2: first node is to be removed
    if (first->data == value) {
        Node* temp = first;
        last->next = first->next;
        delete temp;
        return;
    }

    // Case 3: middle nodes
    Node* cur = first;
    while (cur->next != last) {
        if (cur->next->data == value) {
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            return;
        }
        cur = cur->next;
    }

    // Case 4: last node
    if (last->data == value) {
        Node* temp = last;
        cur->next = last->next;  // eliminate last
        last = cur;              // update last pointer
        delete temp;
        return;
    }

    std::cout << value << " not found.\n";
}

void CircularLinkedList::print() const {
    if (!last) {
        std::cout << "List is empty.\n";
        return;
    }

    Node* t = last->next;  // first node
    do {
        std::cout << t->data << " ";
        t = t->next;
    } while (t != last->next);

    std::cout << "\n";
}
