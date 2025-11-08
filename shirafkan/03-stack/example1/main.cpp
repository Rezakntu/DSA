#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void fcn1 (int n)
{
    if (n==3)
        return;
    else{
        n=n+1;
        fcn1(n);
        cout<<n;
    }
}
/////////////////////////////

int main()
{
    fcn1(1);

    getch();
}


