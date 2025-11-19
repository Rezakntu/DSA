#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

void addBegin(Node** head, int item)
{
    Node* n = new Node();
    n->data = item;

    if (*head == nullptr)
    {
        // First node
        n->next = n;   // Points to itself
        *head = n;
        return;
    }

    // Otherwise, insert before the current head
    Node* t = *head;

    // Traverse to last node
    while (t->next != *head)
        t = t->next;

    n->next = *head;  // New node points to old head
    t->next = n;      // Last node points to new node
    *head = n;        // New node becomes head
}

void show(Node* head)
{
    if (head == nullptr)
        return;

    Node* t = head;

    do
    {
        cout << t->data << " ";
        t = t->next;
    }
    while (t != head);

    cout << endl;
}
