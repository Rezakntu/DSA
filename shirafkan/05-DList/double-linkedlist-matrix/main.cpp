#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////
struct Node {
    int data;
    Node* right;
    Node* down;
};

/////////////////////////////////////////////////////////
Node* buildList(int a[][3], int i, int j, int n, int m)
{
    if (i >= n || j >= m)
        return nullptr;

    Node* t = new Node();
    t->data = a[i][j];

    t->right = buildList(a, i, j + 1, n, m);
    t->down  = buildList(a, i + 1, j, n, m);

    return t;
}

/////////////////////////////////////////////////////////
void display(Node* head)
{
    Node* row = head;

    while (row != nullptr)
    {
        Node* col = row;
        while (col != nullptr)
        {
            cout << col->data << " ";
            col = col->right;
        }
        cout << "\n";
        row = row->down;
    }
}

/////////////////////////////////////////////////////////
int main()
{
    int a[2][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    Node* head = buildList(a, 0, 0, 2, 3);

    display(head);

    return 0;
}
