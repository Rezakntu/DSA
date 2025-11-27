#include "BubbleSort.h"
#include <iostream>

void BubbleSort::sort(std::vector<int>& data)
{
    bool sorted = false;
    int stepCount = 0;
    int n = static_cast<int>(data.size());

    while (!sorted)
    {
        sorted = true;

        for (int i = 0; i < n - 1; i++)
        {
            stepCount++;

            if (data[i] > data[i + 1])
            {
                std::swap(data[i], data[i + 1]);
                sorted = false;
            }

            printStep(data, stepCount);
        }

        std::cout << "-----------------\n";
        n--; // Optimization: last element is already sorted
    }
}

void BubbleSort::printStep(const std::vector<int>& data, int step) const
{
    std::cout << step << " : ";
    for (int x : data)
        std::cout << x << "  ";
    std::cout << "\n";
}
