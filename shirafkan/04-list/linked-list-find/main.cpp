#include <iostream>
#include <stdexcept>
using namespace std;

/////////////////////////////////////
// Node class (modern C++)
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/////////////////////////////////////
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    /////////////////////////////////////
    // Add new value at the beginning
    void addBegin(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    /////////////////////////////////////
    // Recursive helper function
    int findKth(Node* node, int k) const {
        if (!node)
            throw out_of_range("k is larger than the list length");

        if (k == 1)
            return node->data;

        return findKth(node->next, k - 1);
    }

    /////////////////////////////////////
    int findKth(int k) const {
        if (k <= 0)
            throw invalid_argument("k must be positive");

        return findKth(head, k);
    }

    /////////////////////////////////////
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

/////////////////////////////////////
int main() {
    LinkedList list;

    list.addBegin(5);
    list.addBegin(4);
    list.addBegin(6);
    list.addBegin(8);   // List: 8 -> 6 -> 4 -> 5

    try {
        cout << list.findKth(4);   // returns 5
    }
    catch (const exception& e) {
        cout << "Error: " << e.what();
    }

    return 0;
}
