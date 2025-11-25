#include "BinaryHeap.h"
#include <iostream>

int main() {
    BinaryHeap h(11);

    h.add(5);
    h.add(3);
    h.add(4);
    h.add(2);

    h.deleteKey(1);

    std::cout << h.extractMin() << "\n";
    std::cout << h.getMin()     << "\n";

    h.decreaseKey(2, 1);
    std::cout << h.getMin()     << "\n";
}
