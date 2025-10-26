#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x) ;

int main() {
    int a[] = {2, 5, 12, 16, 23, 32, 54, 58, 65, 69, 72, 76, 79, 86};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    int x = 65;
    int ans = binarySearch(a, n, x);
    if (ans != -1)
        cout << "Element " << x << " found at index " << ans
             << " (value = " << a[ans] << ")" << endl;
    else
        cout << "Element " << x << " not found in array." << endl;
    return 0;
}

int binarySearch(int a[], int n, int x) {
    int mid, flag = 0, first = 0, last = n-1;
    while(first <= last && !flag) {
        mid = (first + last)/2;
        if(x < a[mid])
            last = mid -1;
        else if(x > a[mid])
            first = mid + 1;
        else {
            flag = 1;
            return mid;
        }
    }//end while
    return -1;
}