#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void add_begin(Node*& head, int item)
{
    Node* n = new Node{item, head};
    head = n;
}

void del(Node*& head, int item)
{
    // Remove matching nodes from the beginning
    while (head != nullptr && head->data == item)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;
    Node* prev = nullptr;

    // Remove matching nodes in the middle
    while (curr != nullptr)
    {
        if (curr->data == item)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void show(Node* t)
{
    while (t != nullptr)
    {
        cout << t->data << "  ";
        t = t->next;
    }
    cout << "\n------------------------\n";
}

int main()
{
    Node* head = nullptr;

    add_begin(head, 13);
    add_begin(head, 14);
    add_begin(head, 13);
    add_begin(head, 12);
    add_begin(head, 11);
    add_begin(head, 13);

    show(head);

    del(head, 13);

    show(head);

    return 0;
}
