#include <iostream>
#include "SelectionSort.h"

int main() {
    std::vector<int> a = {10, 30, 17, 12, 1, 21, 15};

    SelectionSort::sort(a);

    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
