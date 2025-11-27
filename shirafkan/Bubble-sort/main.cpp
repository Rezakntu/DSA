#include <iostream>
#include <vector>
#include "BubbleSort.h"

int main() {
    std::vector<int> a = {5,1,4,2,8,3,7,6};

    BubbleSort sorter;
    sorter.sort(a);

    std::cout << "Sorted: ";
    for (int x : a)
        std::cout << x << " ";
}
