#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Utility: create new node
Node* create(int value) {
    return new Node(value);
}

// Count length of list
int getLength(const Node* n) {
    int c = 0;
    while (n) {
        n = n->next;
        c++;
    }
    return c;
}

// Add d zeros in front of a list
Node* addZero(Node* head, int count) {
    if (!head) return nullptr;

    Node* newHead = new Node(0);
    count--;

    Node* curr = newHead;
    while (count--) {
        curr->next = new Node(0);
        curr = curr->next;
    }
    curr->next = head;

    return newHead;
}

// Recursive subtraction (digit by digit), returns a new list
Node* subtractRecursive(Node* l1, Node* l2, bool& borrow) {
    if (!l1 && !l2 && !borrow)
        return nullptr;

    Node* nextNode = subtractRecursive(l1 ? l1->next : nullptr,
                                       l2 ? l2->next : nullptr,
                                       borrow);

    int d1 = l1 ? l1->data : 0;
    int d2 = l2 ? l2->data : 0;

    if (borrow) {
        d1--;
        borrow = false;
    }

    if (d1 < d2) {
        d1 += 10;
        borrow = true;
    }

    int diff = d1 - d2;
    Node* result = new Node(diff);
    result->next = nextNode;

    return result;
}

// Main subtract function: aligns lengths, chooses larger number
Node* subtract(Node* l1, Node* l2) {
    if (!l1 && !l2) return nullptr;

    int len1 = getLength(l1);
    int len2 = getLength(l2);

    Node *larger = nullptr, *smaller = nullptr;

    Node* t1 = l1;
    Node* t2 = l2;

    // Make lengths equal by padding zeroes
    if (len1 != len2) {
        larger = (len1 > len2) ? l1 : l2;
        smaller = (len1 > len2) ? l2 : l1;

        smaller = addZero(smaller, abs(len1 - len2));
    }
    else {
        // Compare lists to find larger
        while (l1 && l2) {
            if (l1->data != l2->data) {
                larger  = (l1->data > l2->data) ? t1 : t2;
                smaller = (l1->data > l2->data) ? t2 : t1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    bool borrow = false;
    return subtractRecursive(larger, smaller, borrow);
}

// Print the number stored in list
void show(const Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << "\n";
}

int main() {
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);   // number = 123

    Node* h2 = new Node(4);         // number = 4

    Node* r = subtract(h1, h2);     // 123 - 4 = 119

    show(r);                        // outputs: 119

    return 0;
}
