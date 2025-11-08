#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void fcn2 (int n)
{
    if (n>=3)
    {
        fcn2(n-1);
        cout<<'a';
        cout<< n;
        cout<<'b';
    }
}
/////////////////////////////

int main()
{
    fcn2(4);

    getch();
}

