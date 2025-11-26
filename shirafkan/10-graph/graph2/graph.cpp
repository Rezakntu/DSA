#include "Graph.h"

Graph::Graph(int vertices)
{
    adj.resize(vertices);
}

void Graph::addEdge(int src, int dest, int weight)
{
    if (src < 0 || src >= adj.size() ||
        dest < 0 || dest >= adj.size())
    {
        throw std::out_of_range("Invalid vertex index");
    }

    adj[src].push_back({dest, weight});
}

void Graph::print() const
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (const auto& edge : adj[i])
        {
            std::cout << i << " -> " << edge.dest
                      << " : " << edge.weight << "\n";
        }
        std::cout << "\n";
    }
}
