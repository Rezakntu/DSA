#include "MinHeap.h"

MinHeap::MinHeap(size_t capacity)
    : heap(capacity), capacity(capacity), size(0) {}

bool MinHeap::isFull() const {
    return size == capacity;
}

bool MinHeap::isEmpty() const {
    return size == 0;
}

void MinHeap::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void MinHeap::add(int item) {
    if (isFull())
        return;

    size++;
    int i = size - 1;
    heap[i] = item;

    // Bubble up for MIN heap
    while (i != 0 && heap[i] < heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::print() const {
    for (size_t i = 0; i < size; i++)
        std::cout << heap[i] << "  ";
    std::cout << std::endl;
}
