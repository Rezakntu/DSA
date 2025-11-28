#include <iostream>
#include "MergeSort.h"

int main() {
    std::vector<int> a = {5,2,4,7,1,3,2,6};

    MergeSort ms;
    ms.sort(a);

    for (int x : a)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
