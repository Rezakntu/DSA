#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList dll;

    dll.create(5);
    dll.create(3);
    dll.create(8);
    dll.create(12);

    dll.show();

    dll.deleteNode(25);   // not found
    dll.show();

    dll.deleteNode(5);    // delete head
    dll.show();

    dll.deleteNode(12);   // delete last
    dll.show();

    dll.deleteNode(8);    // delete middle
    dll.show();
}
