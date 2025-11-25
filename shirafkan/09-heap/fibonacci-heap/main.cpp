#include "FibonacciHeap.h"
#include <iostream>

int main() {
    FibonacciHeap fh;
    auto a = fh.insert(10);
    auto b = fh.insert(3);
    auto c = fh.insert(7);

    std::cout << "min = " << fh.minimum()->key << "\n"; // 3

    fh.decrease_key(c, 1); // decrease 7->1
    std::cout << "min after decrease = " << fh.minimum()->key << "\n"; // 1

    fh.extract_min();
    std::cout << "min after extract = " << (fh.minimum()? fh.minimum()->key : -1) << "\n";

    return 0;
}
