#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList dll;

    dll.add_first(3);        // 3
    dll.add_first(2);        // 2 -> 3
    dll.add_first(1);        // 1 -> 2 -> 3

    // Insert after the third node (h->next->next in your original code)
    DoublyLinkedList::Node* third = dll.head_ptr()
                                        ->next.get()        // second node
                                        ->next.get();       // third node

    dll.add_after(third, 4); // 1 -> 2 -> 3 -> 4

    dll.show();
}
