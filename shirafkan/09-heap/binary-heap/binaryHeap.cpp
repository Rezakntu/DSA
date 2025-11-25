#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity)
    : heap(capacity), heapSize(0), capacity(capacity) {}

// ----------------------------------------
void BinaryHeap::swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// ----------------------------------------
void BinaryHeap::add(int key) {
    if (heapSize == capacity) {
        std::cout << "Overflow: Could not insert\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    heap[i] = key;

    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// ----------------------------------------
void BinaryHeap::decreaseKey(int i, int newVal) {
    heap[i] = newVal;

    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// ----------------------------------------
int BinaryHeap::extractMin() {
    if (heapSize <= 0)
        return INT_MAX;

    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    heapify(0);
    return root;
}

// ----------------------------------------
void BinaryHeap::deleteKey(int index) {
    decreaseKey(index, INT_MIN);
    extractMin();
}

// ----------------------------------------
void BinaryHeap::heapify(int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < heapSize && heap[l] < heap[smallest])
        smallest = l;

    if (r < heapSize && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

// ----------------------------------------
bool BinaryHeap::isEmpty() const {
    return heapSize == 0;
}

// ----------------------------------------
int BinaryHeap::getMin() const {
    return heapSize == 0 ? INT_MAX : heap[0];
}

// ----------------------------------------
int BinaryHeap::size() const {
    return heapSize;
}
