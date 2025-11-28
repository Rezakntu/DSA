#include <iostream>
#include <vector>
#include "BubbleSort.h"

int main()
{
    std::vector<int> a = {5, 1, 4, 2, 8};

    BubbleSort sorter;
    sorter.sort(a);

    std::cout << "\nFinal sorted array:\n";
    for (int x : a)
        std::cout << x << "  ";

    return 0;
}
