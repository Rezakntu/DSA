#include "MaxHeap.h"

MaxHeap::MaxHeap(const std::vector<int>& arr)
    : data(arr) {}

/*
 * Restores max-heap property at index i
 */
void MaxHeap::heapify(int i) {
    int n = data.size();
    int largest = i;

    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(largest);
    }
}

/*
 * Builds a max heap from unordered array
 */
void MaxHeap::buildHeap() {
    for (int i = data.size() / 2 - 1; i >= 0; --i)
        heapify(i);
}

void MaxHeap::print() const {
    for (int v : data)
        std::cout << v << " ";
    std::cout << "\n";
}
