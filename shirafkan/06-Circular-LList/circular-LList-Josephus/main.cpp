#include <iostream>
#include "JosephusList.h"

int main() {
    JosephusList circle;

    circle.createList(46);

    std::cout << "Josephus Position: " << circle.solve() << "\n";

    return 0;
}
