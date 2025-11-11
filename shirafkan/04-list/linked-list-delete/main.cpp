#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* start = nullptr;

Node* create_node(int v) {
    Node* n = new Node();
    n->data = v;
    n->next = nullptr;
    return n;
}

void insert_begin() {
    int v;
    cout << "Data: ";
    cin >> v;

    Node* n = create_node(v);
    n->next = start;
    start = n;
}

void del_pos() {
    if (start == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    int pos;
    cout << "Position: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid" << endl;
        return;
    }

    Node* s = start;
    Node* p = nullptr;

    if (pos == 1) {
        start = start->next;
        delete s;
        return;
    }

    int count = 1;
    while (s != nullptr && count < pos) {
        p = s;
        s = s->next;
        count++;
    }

    if (s == nullptr) {
        cout << "Out of range" << endl;
        return;
    }

    p->next = s->next;
    delete s;
}

void show() {
    if (start == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* n = start;
    cout << "Elements: ";
    while (n != nullptr) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "NULL" << endl;
}

int main() {
    while (true) {
        cout << "1. Insert at beginning\n";
        cout << "2. Delete position\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter (1-4): ";

        int x;
        cin >> x;

        switch (x) {
            case 1: insert_begin(); break;
            case 2: del_pos(); break;
            case 3: show(); break;
            case 4: return 0;
            default: cout << "Invalid choice" << endl;
        }

        cout << endl;
    }
}
