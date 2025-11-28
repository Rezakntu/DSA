#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& data) const {
    int n = static_cast<int>(data.size());

    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;

        // Move elements of data[0..i-1] that are greater than key
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}
