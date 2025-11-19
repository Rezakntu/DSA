#include <iostream>
#include "CircularDoublyList.h"

int main() {
    CircularDoublyList list;

    list.addBegin(13);
    list.addBegin(12);
    list.addBegin(11);

    list.display();

    list.addEnd(14);
    list.display();

    return 0;
}
