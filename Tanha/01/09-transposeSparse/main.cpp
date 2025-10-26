#include <iostream>
using namespace std;

struct Sparse {
    int row;
    int col;
    int value;
};

// Function to compute transpose of a sparse matrix
void transposeSparse(Sparse mat[], Sparse Tmat[]) {
    int n = mat[0].value;  // number of non-zero elements

    // Swap dimensions
    Tmat[0].row = mat[0].col;
    Tmat[0].col = mat[0].row;
    Tmat[0].value = n;

    if (n > 0) {
        int current_Tm = 1;
        // For each column i in original matrix
        for (int i = 0; i < mat[0].col; i++) {
            // Scan all non-zero entries
            for (int j = 1; j <= n; j++) {
                if (mat[j].col == i) {
                    // Transpose by swapping row and col
                    Tmat[current_Tm].row = mat[j].col;
                    Tmat[current_Tm].col = mat[j].row;
                    Tmat[current_Tm].value = mat[j].value;
                    current_Tm++;
                }
            }
        }
    }
}

// Helper to print sparse matrix
void printSparse(Sparse mat[]) {
    int n = mat[0].value;
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i <= n; i++)
        cout << mat[i].row << "\t" << mat[i].col << "\t" << mat[i].value << endl;
}

int main() {
    // Example 3x3 matrix:
    // [0 0 5]
    // [1 0 0]
    // [0 2 0]
    Sparse mat[10] = {
        {3, 3, 3},  // header: rows, cols, non-zero count
        {0, 2, 5},
        {1, 0, 1},
        {2, 1, 2}
    };

    Sparse Tmat[10]; // result

    cout << "Original Sparse Matrix:\n";
    printSparse(mat);

    transposeSparse(mat, Tmat);

    cout << "\nTransposed Sparse Matrix:\n";
    printSparse(Tmat);

    return 0;
}
