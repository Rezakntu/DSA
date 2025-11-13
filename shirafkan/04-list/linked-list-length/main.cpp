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

int len(Node* head) {
    int count = 0;
    Node* x = head;
    while (x != nullptr) {
        count++;
        x = x->next;
    }
    return count;
}

int len_rec(Node* head) {
    if (head == nullptr)
        return 0;
    return 1 + len_rec(head->next);
}

int main() {
    Node* head = nullptr;

    add_begin(head, 11);
    add_begin(head, 32);   // 32 -> 11
    add_begin(head, 47);   // 47 -> 32 -> 11

    cout << len(head) << endl;
    cout << len_rec(head) << endl;

    // Cleanup memory (good practice)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
