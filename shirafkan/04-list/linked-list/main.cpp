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
        cout << "1. insert at begin" << endl;
        cout << "2. insert at end" << endl;
        cout << "3. show list" << endl;
        cout << "4. exit" << endl;
        cout << "enter(1..4): ";

        int x;
        cin >> x;

        switch (x) {
            case 1: insert_begin(); break;
            case 2: insert_last(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid option" << endl;
        }
        cout << endl;
    }
}
