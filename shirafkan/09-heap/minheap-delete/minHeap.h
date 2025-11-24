#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
public:
    explicit MinHeap(int capacity);

    void add(int item);      // Insert item
    int remove();            // Extract min
    int size() const;        // Current heap size
    bool empty() const;

    void print() const;      // Debug print

private:
    std::vector<int> heap;   // Internal array
    int capacity;
    int heapSize;

    void heapify(int i);
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i)   const { return 2 * i + 1; }
    int right(int i)  const { return 2 * i + 2; }
};

#endif
