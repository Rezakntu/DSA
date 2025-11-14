#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

void addBegin(Node*& head, int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void show(const Node* head)
{
    const Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

void middle(const Node* head)
{
    const Node* slow = head;
    const Node* fast = head;

    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << "Middle element: " << slow->data;
}

int main()
{
    Node* head = nullptr;

    addBegin(head, 5);
    addBegin(head, 4);
    addBegin(head, 3);
    addBegin(head, 2);
    addBegin(head, 1);    // 1 -> 2 -> 3 -> 4 -> 5

    show(head);
    middle(head);

    return 0;
}
