#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <climits>
#include <iostream>

class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 11);

    void add(int key);
    void decreaseKey(int index, int newVal);
    int extractMin();
    void deleteKey(int index);

    bool isEmpty() const;
    int getMin() const;
    int size() const;

private:
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i)   const { return 2 * i + 1; }
    int right(int i)  const { return 2 * i + 2; }

    void heapify(int i);
    void swap(int& a, int& b);

private:
    std::vector<int> heap;   // dynamic array for heap
    int heapSize;
    int capacity;
};

#endif
