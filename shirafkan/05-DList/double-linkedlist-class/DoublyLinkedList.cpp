#include "DoublyLinkedList.h"

void DoublyLinkedList::create_list(int value) {
    // Just append at the end
    add_after(value, 999999999);
}

void DoublyLinkedList::add(int value) {
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        head = std::move(newNode);
        tail = head.get();
        std::cout << "Element inserted\n";
        return;
    }

    head->prev = newNode.get();
    newNode->next = std::move(head);
    head = std::move(newNode);

    std::cout << "Element inserted\n";
}

void DoublyLinkedList::add_after(int value, int pos) {
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
        head = std::move(newNode);
        tail = head.get();
        std::cout << "Element inserted\n";
        return;
    }

    Node* curr = head.get();
    for (int i = 1; i < pos && curr->next; i++)
        curr = curr->next.get();

    // Insert after curr
    newNode->prev = curr;

    if (curr->next) {
        newNode->next = std::move(curr->next);
        newNode->next->prev = newNode.get();
    } else {
        tail = newNode.get();
    }

    curr->next = std::move(newNode);

    std::cout << "Element inserted\n";
}

void DoublyLinkedList::delete_node(int value) {
    if (!head) {
        std::cout << "Empty list\n";
        return;
    }

    Node* curr = head.get();

    // Delete at head
    if (curr->value == value) {
        head = std::move(curr->next);
        if (head) head->prev = nullptr;
        else tail = nullptr;

        std::cout << "Element deleted\n";
        return;
    }

    while (curr->next) {
        if (curr->next->value == value) {
            auto target = std::move(curr->next);

            curr->next = std::move(target->next);
            if (curr->next)
                curr->next->prev = curr;
            else
                tail = curr;

            std::cout << "Element deleted\n";
            return;
        }
        curr = curr->next.get();
    }

    std::cout << "Element " << value << " not found\n";
}

void DoublyLinkedList::search(int value) {
    Node* curr = head.get();
    int pos = 1;

    while (curr) {
        if (curr->value == value) {
            std::cout << "Found at position " << pos << "\n";
            return;
        }
        curr = curr->next.get();
        pos++;
    }

    std::cout << "Not found\n";
}

void DoublyLinkedList::show() {
    if (!head) {
        std::cout << "List empty\n";
        return;
    }

    Node* curr = head.get();
    std::cout << "List: ";

    while (curr) {
        std::cout << curr->value << " <-> ";
        curr = curr->next.get();
    }
    std::cout << "NULL\n";
}

void DoublyLinkedList::count() {
    int c = 0;
    Node* curr = head.get();
    while (curr) {
        c++;
        curr = curr->next.get();
    }
    std::cout << "Number of nodes: " << c << "\n";
}

void DoublyLinkedList::reverse() {
    if (!head || !head->next)
        return;

    Node* curr = head.get();
    Node* prevNode = nullptr;

    tail = curr;

    while (curr) {
        Node* nextNode = curr->next.get();

        curr->next.release();
        curr->next.reset(prevNode);

        if (prevNode)
            prevNode->prev = curr;

        prevNode = curr;
        curr = nextNode;
    }

    head.release();
    head.reset(prevNode);
    head->prev = nullptr;

    std::cout << "Reversed\n";
}
