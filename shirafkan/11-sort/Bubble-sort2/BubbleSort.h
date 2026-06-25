#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

class BubbleSort
{
public:
    BubbleSort() = default;

    // Sorts the data (with step-by-step printing)
    void sort(std::vector<int>& data);

private:
    void printStep(const std::vector<int>& data, int step) const;
};

#endif
