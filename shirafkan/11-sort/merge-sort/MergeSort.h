#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
public:
    // Public API: sort a vector in-place
    void sort(std::vector<int>& arr);

private:
    // Internal recursive function
    void mergeSort(std::vector<int>& arr, int left, int right);

    // Merge helper
    void merge(std::vector<int>& arr, int left, int mid, int right);
};

#endif // MERGESORT_H
