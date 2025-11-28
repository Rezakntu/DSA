#include <iostream>
#include <vector>
#include "BubbleSort.h"

int main() {
    std::vector<int> a = {5, 1, 4, 2, 8};

    BubbleSort::sort(a);

    for (int v : a)
        std::cout << v << "  ";
}
