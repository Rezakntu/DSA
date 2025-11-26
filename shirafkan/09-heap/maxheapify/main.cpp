#include "MaxHeap.h"
#include <iostream>

int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    MaxHeap heap(arr);
    heap.buildHeap();

    heap.print();
}
