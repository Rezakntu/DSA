#include "MaxHeap.h"

MaxHeap::MaxHeap(const std::vector<int>& data)
    : arr(data)
{
}

void MaxHeap::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeap::maxHeapify(int i, int heapSize)
{
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < heapSize && arr[left] > arr[largest])
        largest = left;

    if (right < heapSize && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(largest, heapSize);
    }
}

void MaxHeap::buildHeap()
{
    for (int i = arr.size() / 2 - 1; i >= 0; --i)
        maxHeapify(i, arr.size());
}

void MaxHeap::heapSort()
{
    buildHeap();

    int heapSize = arr.size();
    for (int i = arr.size() - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        --heapSize;
        maxHeapify(0, heapSize);
    }
}
