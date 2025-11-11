#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void add_begin(Node*& head, int item) {
    Node* n = new Node();
    n->data = item;
    n->next = head;
    head = n;
}

bool search(Node* head, int x) {
    Node* t = head;
    while (t != nullptr) {
        if (t->data == x)
            return true;
        t = t->next;
    }
    return false;
}

bool search_rec(Node* h, int x) {
    if (h == nullptr)
        return false;
    if (h->data == x)
        return true;
    return search_rec(h->next, x);
}

int main() {
    Node* head = nullptr;

    add_begin(head, 5);
    add_begin(head, 8);
    add_begin(head, 2);
    add_begin(head, 6); // 6 -> 2 -> 8 -> 5

    cout << (search(head, 2) ? "found" : "not found") << endl;
    cout << (search_rec(head, 7) ? "found" : "not found") << endl;

    // Free the memory to prevent leaks
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
