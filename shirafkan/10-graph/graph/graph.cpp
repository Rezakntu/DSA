#include "Graph.h"

Graph::Graph(int vertices)
    : V(vertices), adj(vertices)
{
}

void Graph::addEdge(int src, int dest)
{
    if (src < 0 || src >= V || dest < 0 || dest >= V)
        throw std::out_of_range("Vertex index out of bounds");

    adj[src].push_front(dest);
    adj[dest].push_front(src);   // undirected graph
}

void Graph::show() const
{
    for (int i = 0; i < V; ++i)
    {
        std::cout << i;

        for (int v : adj[i])
            std::cout << " -> " << v;

        std::cout << "\n";
    }
}
