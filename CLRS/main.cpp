#include <iostream>
using namespace std;
int main() {
    cout << "Hello, Reza!" << endl;
    int n = 10;
    int a[] = {1,3,5,2,5,12,9,6,4,3};
    int key, j;
    for (int i = 1; i < n; i++ ) {
        key = a[i];
        j = i-1;
        while (j > 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for (int i = 0; i < n; i++ ) {
        if (i == n-1) cout << a[i] << endl;
        else          cout << a[i] << " , ";
    }
    return 0;
}


