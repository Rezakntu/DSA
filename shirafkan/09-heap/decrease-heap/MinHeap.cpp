#include "MinHeap.h"

MinHeap::MinHeap(int capacity)
        : heap(capacity), capacity(capacity), size(0) {}

void MinHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int MinHeap::parent(int i) const {
    return (i - 1) / 2;
}

void MinHeap::add(int value) {
    if (size == capacity)
        throw std::runtime_error("Heap is full");

    int i = size;
    heap[size++] = value;

    // Bubble up
    while (i != 0 && heap[i] < heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int index, int newValue) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    heap[index] = newValue;

    // Bubble up
    while (index != 0 && heap[index] < heap[parent(index)]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}
