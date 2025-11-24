#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
public:
    explicit MinHeap(int capacity);

    void add(int value);
    void decreaseKey(int index, int newValue);

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    int at(int index) const { return heap[index]; }

private:
    std::vector<int> heap;
    int capacity;
    int size;

    void swap(int& a, int& b);
    int parent(int i) const;
};

#endif
