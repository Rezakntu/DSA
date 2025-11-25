#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
public:
    MinHeap() = default;
    explicit MinHeap(const std::vector<int>& data);

    void build();
    void insert(int value);
    int getMin() const;
    void popMin();
    bool empty() const { return heap.empty(); }
    int size() const { return static_cast<int>(heap.size()); }

    const std::vector<int>& data() const { return heap; }

private:
    std::vector<int> heap;

    void heapifyDown(int i);
    void heapifyUp(int i);
};

#endif
