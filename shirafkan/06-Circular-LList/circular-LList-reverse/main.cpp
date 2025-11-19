#include "CircularList.h"
#include <iostream>

int main() {
    CircularList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    std::cout << "Original: ";
    list.print();

    list.reverse();

    std::cout << "Reversed: ";
    list.print();

    return 0;
}
