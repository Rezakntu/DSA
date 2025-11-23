#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>

class MinHeap {
public:
    explicit MinHeap(size_t capacity);

    void add(int item);
    bool isFull() const;
    bool isEmpty() const;

    void print() const;

private:
    std::vector<int> heap;
    size_t capacity;
    size_t size;

    int parent(int i) const { return (i - 1) / 2; }
    void swap(int &a, int &b);
};

#endif
