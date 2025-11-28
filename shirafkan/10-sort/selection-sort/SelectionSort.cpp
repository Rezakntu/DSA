#include "SelectionSort.h"

void SelectionSort::sort(std::vector<int>& data)
{
    const int n = data.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(data[i], data[minIndex]);
    }
}
