#include <iostream>
#include "CircularList.h"

int main() {
    CircularList original, firstHalf, secondHalf;

    original.addBegin(14);
    original.addBegin(13);
    original.addBegin(12);
    original.addBegin(11);
    original.addBegin(10);

    std::cout << "Original: ";
    original.show();

    original.split(firstHalf, secondHalf);

    std::cout << "\n\nFirst Half : ";
    firstHalf.show();

    std::cout << "\nSecond Half: ";
    secondHalf.show();

    std::cout << "\n";
    return 0;
}
