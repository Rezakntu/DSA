#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Recursive display
void display(const Node* head)
{
    if (!head) {
        cout << "NULL\n";
        return;
    }

    cout << head->data << " -> ";
    display(head->next);
}

// Concatenate list b at end of list a (recursive)
void concat(Node* a, Node* b)
{
    if (!a || !b) {
        cout << "Either list A or list B is NULL\n";
        return;
    }

    if (a->next == nullptr)
        a->next = b;
    else
        concat(a->next, b);
}

// Build linked list from user input
Node* buildList(int count)
{
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter " << count << " values:\n";

    while (count--) {
        int value;
        cin >> value;

        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main()
{
    int n;

    cout << "Number of elements in list A: ";
    cin >> n;
    Node* a = buildList(n);

    cout << "Number of elements in list B: ";
    cin >> n;
    Node* b = buildList(n);

    concat(a, b);

    cout << "\nConcatenated list:\n";
    display(a);

    return 0;
}
