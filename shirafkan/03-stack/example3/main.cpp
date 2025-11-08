#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void fcn3 (int n,int m)
{
    if (n==4)
        return;
    else{
        n=n+1;
        m=m+1;
        fcn3(n,m);
        cout<<n;
        cout<<m;
    }
}
/////////////////////////////

int main()
{
    fcn3(1,4);

    getch();
}

