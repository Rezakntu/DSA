// Graph(adjacency list)
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
////////////////////////////////
struct node
{
    int dest;
    struct node* next;
};
////////////////////////////////
struct AdjList
{
    struct node *head;
};
////////////////////////////////
struct Graph
{
    int V;
    struct AdjList* array;
};
////////////////////////////////
struct node* create(int dest)
{
    struct node* n;
    n = new(struct node);
    n->dest = dest;
    n->next = NULL;
    return n;
}
/////////////////////////////////////////////////////////////
struct Graph* createGraph(int V)
{
    struct Graph* g;

    g =new(struct Graph);
    g->V = V;

    g->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        g->array[i].head = NULL;

    return g;
}
////////////////////////////////////////////////////////
void addEdge(struct Graph* g, int src, int dest)
{
    struct node* n;

    n = create(dest);
    n->next = g->array[src].head;
    g->array[src].head = n;

    n = create(src);
    n->next = g->array[dest].head;
    g->array[dest].head = n;
}

//////////////////////////////////////////////////////////
void show(struct Graph* g)
{
    int i;
    struct node* p;

    for (i = 0; i< g->V; ++i)
    {
        p= g->array[i].head;
        cout<<"\n " << i << " ";

        while (p)
        {
            cout<<" -> "<<p->dest;
            p = p->next;
        }
        cout<<"\n";
    }
}

////////////////////////////////
int main()
{
    int V = 4;
    struct Graph* g;
    g = createGraph(V);

    /*
                   0
                  / \
                 1 -2
                     \
                     3
    */
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    show(g);

    getch();
}
