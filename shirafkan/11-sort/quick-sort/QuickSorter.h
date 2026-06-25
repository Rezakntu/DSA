#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include <vector>

class QuickSorter {
public:
    // Sorts the entire vector
    void sort(std::vector<int>& data);

private:
    // Internal recursive quicksort
    void quickSort(std::vector<int>& data, int p, int r);

    // Partition function
    int partition(std::vector<int>& data, int p, int r);
};

#endif
