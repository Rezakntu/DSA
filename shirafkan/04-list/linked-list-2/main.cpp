#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* start = nullptr;

Node* create_node(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = nullptr;
    return n;
}

void insert_begin() {
    int v;
    cout << "Value: ";
    cin >> v;

    Node* n = create_node(v);
    n->next = start;
    start = n;
}

void insert_last() {
    int v;
    cout << "Value: ";
    cin >> v;

    Node* n = create_node(v);

    if (start == nullptr) {
        start = n;
        return;
    }

    Node* s = start;
    while (s->next != nullptr) {
        s = s->next;
    }

    s->next = n;
}

void insert_pos() {
    int v, pos;
    cout << "Data: ";
    cin >> v;
    cout << "Position: ";
    cin >> pos;

    Node* n = create_node(v);

    if (pos == 1) {
        n->next = start;
        start = n;
        return;
    }

    Node* s = start;
    Node* p = nullptr;
    int count = 1;

    while (s != nullptr && count < pos) {
        p = s;
        s = s->next;
        count++;
    }

    if (count == pos) {
        p->next = n;
        n->next = s;
    } else {
        cout << "Position out of range" << endl;
        delete n;
    }
}

void display() {
    if (start == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* t = start;
    cout << "Elements: ";
    while (t != nullptr) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL" << endl;
}

int main() {
    while (true) {
        cout << "1. insert at begin\n";
        cout << "2. insert at end\n";
        cout << "3. insert at position\n";
        cout << "4. show list\n";
        cout << "5. exit\n";
        cout << "Enter (1..5): ";

        int x;
        cin >> x;

        switch (x) {
            case 1: insert_begin(); break;
            case 2: insert_last(); break;
            case 3: insert_pos(); break;
            case 4: display(); break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }

        cout << endl;
    }
}
