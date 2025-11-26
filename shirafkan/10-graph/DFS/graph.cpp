#include "Graph.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

Graph::Graph(int vertices)
    : vertexCount(vertices),
      adjMatrix(vertices, vector<int>(vertices, 0)) {}


void Graph::addEdge(int src, int dest) {
    if (src >= 0 && src < vertexCount &&
        dest >= 0 && dest < vertexCount)
    {
        adjMatrix[src][dest] = 1;
    }
}


void Graph::dfs(int startVertex)
{
    if (startVertex < 0 || startVertex >= vertexCount) {
        cout << "Invalid starting vertex\n";
        return;
    }

    vector<int> state(vertexCount, 1);   // 1 = unvisited
    stack<int> st;

    st.push(startVertex);

    cout << "DFS Order: ";

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (state[v] == 1) {
            cout << v << " ";
            state[v] = 2;        // mark visited
        }

        // push neighbors (reverse order to match original behavior)
        for (int i = vertexCount - 1; i >= 0; i--) {
            if (adjMatrix[v][i] == 1 && state[i] == 1)
                st.push(i);
        }
    }

    cout << "\n";
}


void Graph::createGraphInteractive()
{
    cout << "Enter edges (src dest), -1 -1 to stop:\n";

    while (true) {
        int src, dest;
        cout << "src: ";
        cin >> src;
        cout << "dest: ";
        cin >> dest;

        if (src == -1 && dest == -1)
            break;

        if (src < 0 || dest < 0 ||
            src >= vertexCount || dest >= vertexCount)
        {
            cout << "Invalid edge. Try again.\n";
            continue;
        }

        addEdge(src, dest);
        cout << "Edge added.\n\n";
    }
}
