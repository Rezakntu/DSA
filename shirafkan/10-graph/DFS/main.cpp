#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
      int vertices;
      cout << "Enter number of vertices: ";
      cin >> vertices;

      Graph g(vertices);

      g.createGraphInteractive();

      int start;
      cout << "Enter starting vertex for DFS: ";
      cin >> start;

      g.dfs(start);

      return 0;
}
