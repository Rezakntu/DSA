#ifndef MAXHEAPSORT_H
#define MAXHEAPSORT_H

#include <vector>

class MaxHeapSort {
public:
    // Performs heap sort in-place
    static void heapSort(std::vector<int>& arr);

private:
    // Heapify subtree at index i (max heap)
    static void maxHeapify(std::vector<int>& arr, int n, int i);
};

#endif
