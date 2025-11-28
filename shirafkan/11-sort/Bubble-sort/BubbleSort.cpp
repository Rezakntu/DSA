#include "BubbleSort.h"

void BubbleSort::swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void BubbleSort::sort(std::vector<int>& data) {
    int n = data.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)  // Already sorted → optimization
            break;
    }
}
