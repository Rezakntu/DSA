#include "MinHeap.h"
#include <algorithm>

MinHeap::MinHeap(const std::vector<int>& data) : heap(data) {
    build();
}

void MinHeap::build() {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MinHeap::getMin() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

void MinHeap::popMin() {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty())
        heapifyDown(0);
}

void MinHeap::heapifyDown(int i) {
    int n = heap.size();

    while (true) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        std::swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

void MinHeap::heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i] >= heap[parent])
            break;

        std::swap(heap[i], heap[parent]);
        i = parent;
    }
}
