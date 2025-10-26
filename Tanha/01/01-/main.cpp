#include <iostream>
#include <utility>  // for std::swap

// Bubble Sort function
void bubbleSort(int arr[], int num) {
    for (int i = 0; i < num - 1; i++) {
        // Last i elements are already in place
        for (int j = num - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
