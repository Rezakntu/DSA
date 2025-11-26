#include "Graph.h"

int main()
{
    Graph g(4);  // 4 vertices: 0,1,2,3

    /*
           0
         /   \
        1 --- 2
               \
                3
    */

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(2, 3, 40);

    g.print();

    return 0;
}
