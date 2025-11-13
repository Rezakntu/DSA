#include <iostream>
using namespace std;

/////////////////////////////////////////////
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/////////////////////////////////////////////
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    /////////////////////////////////////////////
    // Add at beginning
    void add(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    /////////////////////////////////////////////
    // Reverse the linked list (iterative)
    void reverse() {
        if (!head || !head->next)
            return;

        Node *p1 = nullptr, *p2 = head, *p3 = nullptr;

        while (p2 != nullptr) {
            p3 = p2->next;   // save next
            p2->next = p1;   // reverse pointer
            p1 = p2;         // move forward
            p2 = p3;
        }

        head = p1;  // new head
    }

    /////////////////////////////////////////////
    // Display the list
    void display() const {
        if (!head) {
            cout << "The List is Empty\n";
            return;
        }

        Node* n = head;
        while (n != nullptr) {
            cout << n->data << " -> ";
            n = n->next;
        }
        cout << "NULL\n\n";
    }

    /////////////////////////////////////////////
    // Destructor to free memory
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

//////////////////////////////////////////////////////
int main() {
    LinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);

    list.display();   // 3 -> 2 -> 1 -> NULL

    list.reverse();

    list.display();   // 1 -> 2 -> 3 -> NULL

    return 0;
}
