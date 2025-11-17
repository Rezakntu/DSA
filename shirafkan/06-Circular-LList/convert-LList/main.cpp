#include "convert_sll_to_cll.h"
#include <iostream>

int main() {
    SinglyList list;

    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    std::cout << "Before converting:\n";
    list.print();

    list.convert_to_circular();

    std::cout << "After converting to circular:\n";
    list.print();

    return 0;
}
