#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int vertexCount;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices);

    void addEdge(int src, int dest);
    void dfs(int startVertex);
    void createGraphInteractive();
};

#endif
