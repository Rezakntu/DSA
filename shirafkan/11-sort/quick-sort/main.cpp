#include <iostream>
#include <vector>
#include "QuickSorter.h"

int main() {
    std::vector<int> a = {2, 8, 7, 1, 3, 5, 6, 4};

    QuickSorter sorter;
    sorter.sort(a);

    for (int x : a)
        std::cout << x << "  ";

    return 0;
}
