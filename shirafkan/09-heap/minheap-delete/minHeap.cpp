#include "MinHeap.h"
#include <iostream>
#include <climits>

MinHeap::MinHeap(int capacity)
    : capacity(capacity), heapSize(0), heap(capacity)
{
}

void MinHeap::add(int item)
{
    if (heapSize == capacity)
        throw std::overflow_error("Heap is full.");

    int i = heapSize++;
    heap[i] = item;

    // Bubble up
    while (i != 0 && heap[i] < heap[parent(i)]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heapSize && heap[l] < heap[smallest])
        smallest = l;

    if (r < heapSize && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

int MinHeap::remove()
{
    if (heapSize <= 0)
        throw std::underflow_error("Heap is empty.");

    if (heapSize == 1)
        return heap[--heapSize];

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    heapify(0);

    return root;
}

int MinHeap::size() const {
    return heapSize;
}

bool MinHeap::empty() const {
    return heapSize == 0;
}

void MinHeap::print() const
{
    for (int i = 0; i < heapSize; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
}
