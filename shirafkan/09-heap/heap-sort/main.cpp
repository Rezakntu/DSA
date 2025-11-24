#include <iostream>
#include "MaxHeapSort.h"

int main()
{
    std::vector<int> arr = {6, 5, 3, 1, 8, 7, 2, 4};

    MaxHeapSort::heapSort(arr);

    for (int v : arr)
        std::cout << v << " ";

    return 0;
}
