// Graph
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#define N 4
////////////////////////////
struct Node
{
    int  dest;
    int  weight;
    struct Node* next;
};
///////////////////////////
struct Edge
{
    int src;
    int dest;
    int weight;
};
//////////////////////////
struct Graph
{
    struct Node* head[N];
};
//////////////////////////////////////////////////
struct Graph* createGraph(struct Edge e[], int c)
{
    unsigned i;
    int src,dest,weight;
    struct Graph* g;

    g = new(struct Graph);

    for (i = 0; i < N; i++)
        g->head[i] = NULL;

    for (i = 0; i < c; i++)
    {
        src    = e[i].src;
        dest   = e[i].dest;
        weight = e[i].weight;

        struct Node* n;
        n = new(struct Node);
        n->dest   = dest;
        n->weight = weight;

        n->next = g->head[src];

        g->head[src] = n;
    }
    return g;
}
/////////////////////////////////////////////////////////////
void show(struct Graph* g)
{
    struct Node* p;
    int i;

    for (i = 0; i < N; i++)
    {
        p = g->head[i];
        while (p != NULL)
        {
            cout<< i << "->" << p->dest <<" : " << p->weight <<"\n";
            p = p->next;
        }
        cout<<endl;
    }
}
/////////////////////////////////////////////////////////////
int main(void)
{
    /*
           0
           /  \
        1 - 2
             \
              3
    */

    struct Edge e[] ={ { 0,1,10 },{ 0,2,20 }, { 1,2,30 },{ 2,3,40 } };

    struct Graph *g;

    g = createGraph(e, 4);

    show(g);

    getch();
}
