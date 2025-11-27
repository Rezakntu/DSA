#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

class BubbleSort {
public:
    BubbleSort() = default;

    // Sorts the vector in ascending order
    void sort(std::vector<int>& data);

private:
    // Internal helper function
    void swap(int& a, int& b);
};

#endif // BUBBLESORT_H
