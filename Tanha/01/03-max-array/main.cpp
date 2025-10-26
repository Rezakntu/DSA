#include <iostream>
using namespace std;
int findMax(int arr[] ,int n) {

    int max = arr[0];
    for(int i=1;i<n;i++) {
        if(max < arr[i]) max = arr[i];
    }
    return max;
}
int main()
{
    int arr[] = {21,2,32,4,32,5,24,9,87,54,3,22,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = findMax(arr, n);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    std::cout << "maximum : " << max << std::endl;
    return 0;
}
