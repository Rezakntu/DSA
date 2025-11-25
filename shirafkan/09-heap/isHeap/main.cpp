#include <iostream>
#include "HeapChecker.h"

int main()
{
    std::vector<int> x = {90, 15, 10, 7, 12, 2, 7, 3};

    HeapChecker checker(x);

    std::cout << (checker.isMaxHeap() ? "Yes" : "No") << "\n";
}
