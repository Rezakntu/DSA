#include <iostream>
#include <limits>
using namespace std;

/////////////////////////////////////////////
// Node (modern C++)
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

    /////////////////////////////////////////
    // Add new element at beginning
    void add(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    /////////////////////////////////////////
    // Find maximum value in the list
    int getMax() const {
        if (!head) {
            throw runtime_error("List is empty");
        }

        int maximum = numeric_limits<int>::min();
        Node* cur = head;

        while (cur) {
            if (cur->data > maximum)
                maximum = cur->data;
            cur = cur->next;
        }
        return maximum;
    }

    /////////////////////////////////////////
    // Display list
    void show() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    /////////////////////////////////////////
    // Destructor (prevents memory leaks)
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

/////////////////////////////////////////////////////////
int main() {
    LinkedList list;

    list.add(5);
    list.add(26);
    list.add(7);

    list.show();

    cout << "\nmax = " << list.getMax();

    return 0;
}
