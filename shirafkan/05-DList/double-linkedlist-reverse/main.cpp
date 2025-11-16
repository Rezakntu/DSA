#include <iostream>
using namespace std;

///////////////////////////////////////
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* start = nullptr;

/////////////////////////////////////////////////////////
void create(int item)
{
    Node* t = new Node;
    t->data = item;
    t->next = nullptr;
    t->prev = nullptr;

    if (start == nullptr) {
        start = t;
    } else {
        Node* s = start;
        while (s->next != nullptr)
            s = s->next;

        s->next = t;
        t->prev = s;
    }
}

/////////////////////////////////////////////////////////
void show()
{
    if (start == nullptr) {
        cout << "empty\n";
        return;
    }

    Node* q = start;
    while (q != nullptr) {
        cout << q->data << " <-> ";
        q = q->next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////
void reverseList()
{
    if (start == nullptr || start->next == nullptr)
        return;

    Node* p1 = start;
    Node* p2 = p1->next;

    p1->next = nullptr;
    p1->prev = p2;

    while (p2 != nullptr)
    {
        p2->prev = p2->next;
        p2->next = p1;

        p1 = p2;
        p2 = p2->prev;
    }

    start = p1;
}

/////////////////////////////////////////////////////////
int main()
{
    create(4);
    create(7);
    create(2);

    show();         // 4 <-> 7 <-> 2 <-> NULL

    reverseList();

    show();         // 2 <-> 7 <-> 4 <-> NULL

    return 0;
}
