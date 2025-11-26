#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>

class Graph
{
public:
    explicit Graph(int vertices);

    void addEdge(int src, int dest);
    void show() const;

private:
    int V;                               // number of vertices
    std::vector<std::list<int>> adj;     // adjacency list
};

#endif
