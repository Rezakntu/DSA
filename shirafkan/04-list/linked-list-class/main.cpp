#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;

    list.add_begin(5);
    list.add_begin(4);
    list.add_begin(3);
    list.add_begin(2);
    list.add_begin(1);

    list.show();

    std::cout << "Middle: " << list.middle() << "\n";
    std::cout << "4th element: " << list.find_kth(4) << "\n";

    list.delete_all(3);
    list.show();

    return 0;
}
