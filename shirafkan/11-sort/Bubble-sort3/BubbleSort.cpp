#include "BubbleSort.h"

void BubbleSort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort::sort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    sortRecursive(arr, arr.size());
}

void BubbleSort::sortRecursive(std::vector<int>& arr, std::size_t n) {
    if (n == 1) return;

    for (std::size_t i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    sortRecursive(arr, n - 1);
}
