#include <iostream>
using namespace std;

/////////////////////////////////////////////
// Node definition (modern C++)
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/////////////////////////////////////////////
class LinkedList {
private:
    Node* head;

    // --- Recursive helper ---
    Node* reverseRec(Node* node) {
        // Base case: empty or last node
        if (!node || !node->next)
            return node;

        Node* newHead = reverseRec(node->next);

        node->next->next = node;  // reverse the link
        node->next = nullptr;     // old head becomes tail

        return newHead;
    }

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
    // Recursive reverse wrapper
    void reverse() {
        head = reverseRec(head);
    }

    /////////////////////////////////////////////
    // Display list
    void show() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    /////////////////////////////////////////////
    // Free memory
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

/////////////////////////////////////////////////////////////
int main() {
    LinkedList list;

    list.add(5);
    list.add(9);
    list.add(2);

    list.show();      // 2->9->5->NULL

    list.reverse();

    cout << "\n";
    list.show();      // 5->9->2->NULL

    return 0;
}
