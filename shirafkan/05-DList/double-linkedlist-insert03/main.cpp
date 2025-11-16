#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList dll;

    dll.addFirst(2);                    // 2
    dll.addFirst(1);                    // 1 -> 2
    dll.addLast(4);                     // 1 -> 2 -> 4

    dll.addAfter(dll.head_ptr()->next.get(), 3);  // 1 -> 2 -> 3 -> 4

    // Add after last node
    DoublyLinkedList::Node* last =
        dll.head_ptr()->next.get()->next.get()->next.get();

    dll.addAfter(last, 5);              // 1 -> 2 -> 3 -> 4 -> 5

    dll.show();
}
