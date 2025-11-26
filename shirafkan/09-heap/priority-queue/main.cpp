#include "PriorityQueue.h"

int main() {
    PriorityQueue pq;

    pq.push(45, 4);
    pq.push(25, 2);
    pq.push(15, 1);
    pq.push(35, 3);

    pq.display();

    pq.pop();

    pq.display();

    return 0;
}
