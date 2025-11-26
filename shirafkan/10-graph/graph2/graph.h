#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <memory>

class Graph
{
public:
    struct Edge {
        int dest;
        int weight;
    };

    explicit Graph(int vertices);

    void addEdge(int src, int dest, int weight);
    void print() const;

private:
    std::vector<std::vector<Edge>> adj;
};

#endif
