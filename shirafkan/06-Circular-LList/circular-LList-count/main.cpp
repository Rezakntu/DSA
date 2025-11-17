#include "CircularList.h"
#include <iostream>

int main() {
    CircularList list;

    list.push_front(5);
    list.push_front(2);
    list.push_front(13);
    list.push_front(25);

    list.print();
    std::cout << "Count = " << list.count() << "\n";

    return 0;
}
