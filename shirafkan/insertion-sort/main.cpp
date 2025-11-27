#include <iostream>
#include <vector>
#include "InsertionSort.h"

int main() {
    std::vector<int> numbers = {5, 2, 4, 6, 1, 3};

    InsertionSort sorter;
    sorter.sort(numbers);

    for (int value : numbers) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
