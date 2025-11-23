#include <iostream>
#include <climits>
#include <conio.h>
using namespace std;

int* x;
int heapSize;
int capacity;

void swapVal(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void add(int item)
{
    if (heapSize == capacity)
        return;

    heapSize++;
    int i = heapSize - 1;
    x[i] = item;

    while (i != 0 && x[i] < x[parent(i)])
    {
        swapVal(&x[i], &x[parent(i)]);
        i = parent(i);
    }
}

int main()
{
    x = new int[6];

    heapSize = 0;
    capacity = 6;

    add(4);
    add(8);
    add(3);
    add(1);
    add(5);
    add(2);

    for(int i = 0; i < 6; i++)
        cout << x[i] << "  ";

    getch();
}
