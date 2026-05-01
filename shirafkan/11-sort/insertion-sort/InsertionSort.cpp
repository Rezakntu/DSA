#include "InsertionSort.h"

// Insertion sort builds a sorted prefix of the array one element at a time.
// At each step, we "insert" the current element into its correct position
// among the elements before it.
void InsertionSort::sort(std::vector<int>& data) const {
    // n is the number of items to sort.
    int n = static_cast<int>(data.size());

    // Start at index 1 because a single element at index 0 is already sorted.
    for (int i = 1; i < n; ++i) {
        // key is the value we want to insert into the sorted left side.
        int key = data[i];
        // j points to the last element in the sorted left side.
        int j = i - 1;

        // Shift every element greater than key one position to the right.
        // This creates the correct empty spot for key.
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }

        // Place key into the empty position. At this point,
        // data[0..i] is sorted.
        data[j + 1] = key;
    }
}
