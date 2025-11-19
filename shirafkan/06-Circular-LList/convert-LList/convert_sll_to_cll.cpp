#include "convert_sll_to_cll.h"

SinglyList::SinglyList() : head(nullptr) {}

SinglyList::~SinglyList() {
    if (!head) return;

    Node* curr = head;
    Node* next = nullptr;

    // If list is circular, break it for safe deletion
    if (head->next) {
        Node* temp = head->next;
        while (temp && temp != head) {
            temp = temp->next;
            if (temp == head) {  // found circle, break
                head->next = nullptr;
                break;
            }
        }
    }

    // Delete normally as singly list
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void SinglyList::push_front(int value) {
    Node* n = new Node(value);
    n->next = head;
    head = n;
}

void SinglyList::convert_to_circular() {
    if (!head || !head->next) return;

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    tail->next = head;   // Make list circular
}

void SinglyList::print() const {
    if (!head) {
        std::cout << "List empty\n";
        return;
    }

    const Node* start = head;
    const Node* curr = head;

    // Detect whether it is circular
    bool is_circular = false;

    while (curr->next != nullptr) {
        if (curr->next == start) {
            is_circular = true;
            break;
        }
        curr = curr->next;
    }

    // Print circular list
    if (is_circular) {
        const Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "\n";
        return;
    }

    // Print normal list
    curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}
