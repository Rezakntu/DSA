#pragma once
#include <memory>
#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int value{};
        std::unique_ptr<Node> next;
        Node* prev = nullptr;

        Node(int v) : value(v) {}
    };

    std::unique_ptr<Node> head;
    Node* tail = nullptr;

public:
    DoublyLinkedList() = default;

    // Creates or appends a node at the end
    void create_list(int value);

    // Insert at beginning
    void add(int value);

    // Insert after position (1-based)
    void add_after(int value, int position);

    // Delete a node by value
    void delete_node(int value);

    // Search for a value
    void search(int value);

    // Display the list
    void show();

    // Count number of nodes
    void count();

    // Reverse the list
    void reverse();
};
