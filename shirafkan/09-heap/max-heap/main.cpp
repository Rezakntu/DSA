#include <iostream>
#include "MaxHeap.h"

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element " << i << ": ";
        std::cin >> values[i];
    }

    MaxHeap heap(values);
    heap.heapSort();

    std::cout << "\nSorted (Max-Heap Sort):\n";
    for (int x : heap.data())
        std::cout << x << "\n";

    return 0;
}
