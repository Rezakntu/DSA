#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <iostream>

class MaxHeap {
private:
    std::vector<int> data;

    void heapify(int i);

public:
    MaxHeap() = default;
    explicit MaxHeap(const std::vector<int>& arr);

    void buildHeap();
    void print() const;

    const std::vector<int>& getData() const { return data; }
};

#endif
