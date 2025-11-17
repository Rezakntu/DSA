#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct Node
{
    int data;
    Node* next;
};

/// Adds a new node at the beginning of the circular linked list
void addBegin(Node** head, int item);

/// Displays the list starting from a given node
void show(Node* head);

#endif
