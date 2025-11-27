#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <iostream>

class BubbleSort {
public:
    // Recursive bubble sort (public interface)
    static void sort(std::vector<int>& arr);

private:
    // Internal recursive function
    static void sortRecursive(std::vector<int>& arr, std::size_t n);

    // Modern C++ swap
    static void swap(int& a, int& b);
};

#endif
