#include <iostream>
#include "MinHeap.h"

int main() {
    MinHeap h(5);

    h.add(2);
    h.add(3);
    h.add(5);
    h.add(9);
    h.add(6);

    std::cout << "Before decreaseKey: ";
    for (int i = 0; i < h.getSize(); i++)
        std::cout << h.at(i) << " ";

    h.decreaseKey(3, 1);

    std::cout << "\nAfter decreaseKey:  ";
    for (int i = 0; i < h.getSize(); i++)
        std::cout << h.at(i) << " ";

    return 0;
}
