#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    Node* head = nullptr;

    addBegin(&head, 3);   // 3
    addBegin(&head, 2);   // 2 3
    addBegin(&head, 1);   // 1 2 3

    show(head);           // prints: 1 2 3

    return 0;
}
