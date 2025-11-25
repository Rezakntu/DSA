#include "HeapChecker.h"

HeapChecker::HeapChecker(const std::vector<int>& data)
    : arr(data) {}

bool HeapChecker::isMaxHeap() const
{
    if (arr.empty()) return true;
    return isHeapRecursive(0);
}

bool HeapChecker::isHeapRecursive(int i) const
{
    int n = arr.size();

    // If i is a leaf → valid
    if (i > (n - 2) / 2)
        return true;

    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    bool okLeft  = (left < n  ? arr[i] >= arr[left]  : true);
    bool okRight = (right < n ? arr[i] >= arr[right] : true);

    return okLeft && okRight &&
           isHeapRecursive(left) &&
           isHeapRecursive(right);
}
