#include "QuickSorter.h"
#include <utility> // for std::swap

void QuickSorter::sort(std::vector<int>& data) {
    if (!data.empty())
        quickSort(data, 0, static_cast<int>(data.size()) - 1);
}

void QuickSorter::quickSort(std::vector<int>& data, int p, int r) {
    if (p < r) {
        int q = partition(data, p, r);
        quickSort(data, p, q - 1);
        quickSort(data, q + 1, r);
    }
}

int QuickSorter::partition(std::vector<int>& data, int p, int r) {
    int pivot = data[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[r]);
    return i + 1;
}
