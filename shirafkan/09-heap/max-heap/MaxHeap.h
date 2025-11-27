#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <iostream>

class MaxHeap
{
public:
    MaxHeap() = default;
    explicit MaxHeap(const std::vector<int>& data);

    void buildHeap();
    void heapSort();
    const std::vector<int>& data() const { return arr; }

private:
    std::vector<int> arr;

    void maxHeapify(int i, int heapSize);
    static void swap(int& a, int& b);
};

#endif // MAX_HEAP_H
