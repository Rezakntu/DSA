#include <iostream>
using namespace std;

// Function prototype
int seqSearch(int arr[], int n, int x);

int main() {
    int a[] = {23, 12, 2, 43, 5, 32, 54, 7, 65, 4, 34, 26, 7, 56};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int x = 65;
    int ans = seqSearch(a, n, x);

    if (ans != -1)
        cout << "Element " << x << " found at index " << ans
             << " (value = " << a[ans] << ")" << endl;
    else
        cout << "Element " << x << " not found in array." << endl;

    return 0;
}

// Sequential Search
int seqSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;  // return index if found
    return -1;  // not found
}
