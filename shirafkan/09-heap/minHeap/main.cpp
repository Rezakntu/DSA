#include <iostream>
#include "MinHeap.h"

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter element " << i << ": ";
        std::cin >> arr[i];
    }

    MinHeap heap(arr);

    std::cout << "\nMin-Heap elements:\n";
    for (int v : heap.data()) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::cout << "Min element = " << heap.getMin() << "\n";

    return 0;
}
