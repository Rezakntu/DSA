#include "MinHeap.h"

int main() {
    MinHeap h(6);

    h.add(4);
    h.add(8);
    h.add(3);
    h.add(1);
    h.add(5);
    h.add(2);

    h.remove(); // remove min (1)

    h.print();
}
