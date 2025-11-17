#include "CircularLinkedList.h"

int main() {
    CircularLinkedList cll;

    cll.push_back(3);
    cll.push_back(2);
    cll.push_back(1);

    std::cout << "List: ";
    cll.print();

    cll.remove(2);
    std::cout << "After deleting 2: ";
    cll.print();

    cll.remove(1);
    std::cout << "After deleting 1: ";
    cll.print();

    cll.remove(3);
    std::cout << "After deleting 3: ";
    cll.print();

    return 0;
}
