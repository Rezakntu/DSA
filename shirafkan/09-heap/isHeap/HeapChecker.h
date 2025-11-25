#ifndef HEAPCHECKER_H
#define HEAPCHECKER_H

#include <vector>

class HeapChecker
{
public:
    // Constructor takes an array (vector)
    HeapChecker(const std::vector<int>& data);

    // Returns true if the internal array is a max-heap
    bool isMaxHeap() const;

private:
    std::vector<int> arr;

    // Recursive helper
    bool isHeapRecursive(int i) const;
};

#endif
