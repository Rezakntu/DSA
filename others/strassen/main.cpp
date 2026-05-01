#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For std::setw
#include <cassert> // For assert()

using namespace std;

// Structure to hold counts of multiplications and additions
struct ComputationCounts {
    long long multiplications = 0;
    long long additions = 0;
};

// ---------------- Matrix helper functions ----------------
// Adds two matrices A and B, returns the result C = A + B
// Updates the addition count
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, ComputationCounts& counts) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            counts.additions++; // Increment addition count
        }
    }
    return C;
}

// Subtracts matrix B from matrix A, returns the result C = A - B
// Updates the addition count (subtraction is addition with negative)
vector<vector<int>> subMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, ComputationCounts& counts) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
            counts.additions++; // Increment addition count for subtraction
        }
    }
    return C;
}

// ---------------- Classic O(n^3) multiplication ----------------
// Multiplies matrices A and B using the standard algorithm, returns C = A * B
// Updates the multiplication and addition counts
vector<vector<int>> normalMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, ComputationCounts& counts) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
                counts.multiplications++; // Increment multiplication count
                if (k > 0) { // The first multiplication doesn't involve an addition to an existing sum
                  counts.additions++; // Increment addition count for summing up products
                }
            }
        }
    }
    return C;
}

// ---------------- Strassen multiplication ----------------
// Multiplies matrices A and B using Strassen's algorithm, returns C = A * B
// Updates the multiplication and addition counts
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B, ComputationCounts& counts) {
    int n = A.size();

    // Base case: If matrix size is 1x1, perform simple multiplication
    if (n == 1) {
        // Perform multiplication and update counts
        // Note: For a 1x1 matrix, C[0][0] = A[0][0] * B[0][0]. This is one multiplication.
        // No additions are needed here.
        counts.multiplications++;
        return {{A[0][0] * B[0][0]}};
    }

    // Split matrices into quadrants
    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Recursive calls to Strassen for the 7 products (M1 to M7)
    // Each recursive call will update counts internally.
    // The additions/subtractions needed for intermediate steps are handled by addMatrix/subMatrix.

    // M1 = (A11 + A22) * (B11 + B22)
    auto M1 = strassen(addMatrix(A11, A22, counts), addMatrix(B11, B22, counts), counts);
    // M2 = (A21 + A22) * B11
    auto M2 = strassen(addMatrix(A21, A22, counts), B11, counts);
    // M3 = A11 * (B12 - B22)
    auto M3 = strassen(A11, subMatrix(B12, B22, counts), counts);
    // M4 = A22 * (B21 - B11)
    auto M4 = strassen(A22, subMatrix(B21, B11, counts), counts);
    // M5 = (A11 + A12) * B22
    auto M5 = strassen(addMatrix(A11, A12, counts), B22, counts);
    // M6 = (A21 - A11) * (B11 + B12)
    auto M6 = strassen(subMatrix(A21, A11, counts), addMatrix(B11, B12, counts), counts);
    // M7 = (A12 - A22) * (B21 + B22)
    auto M7 = strassen(subMatrix(A12, A22, counts), addMatrix(B21, B22, counts), counts);

    // Counting the multiplications for the 7 recursive calls
    counts.multiplications += 7;

    // Compute C quadrants
    // C11 = M1 + M4 - M5 + M7
    auto C11 = addMatrix(subMatrix(addMatrix(M1, M4, counts), M5, counts), M7, counts);
    // C12 = M3 + M5
    auto C12 = addMatrix(M3, M5, counts);
    // C21 = M2 + M4
    auto C21 = addMatrix(M2, M4, counts);
    // C22 = M1 - M2 + M3 + M6
    auto C22 = addMatrix(subMatrix(addMatrix(M1, M3, counts), M2, counts), M6, counts);

    // Combine submatrices into the result matrix C
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

// ---------------- Print matrix ----------------
void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int val : row)
            cout << setw(4) << val << " "; // Added setw for better alignment
        cout << endl;
    }
}

// ---------------- Compare two matrices ----------------
bool compareMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n != B.size() || (n > 0 && A[0].size() != B[0].size())) {
        cout << "✘ Matrices have different dimensions.\n";
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) {
                cout << "Matrices differ at (" << i << ", " << j << "): "
                     << A[i][j] << " vs " << B[i][j] << endl;
                return false;
            }
        }
    }
    cout << "Matrices are identical.\n";
    return true;
}

// ---------------- Main function ----------------
int main() {
    srand(time(0)); // Seed random number generator

    // -------- Example 1: 2x2 --------
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "=== Example 1: 2x2 ===\n";
    cout << "Matrix A:\n"; printMatrix(A);
    cout << "Matrix B:\n"; printMatrix(B);

    ComputationCounts counts1_normal = {0, 0};
    auto C1_normal = normalMultiply(A, B, counts1_normal);
    cout << "\nResult (Normal Multiplication):\n";
    printMatrix(C1_normal);
    cout << "Normal Multiply Computations: " << counts1_normal.multiplications << " multiplications, " << counts1_normal.additions << " additions.\n";

    ComputationCounts counts1_strassen = {0, 0};
    auto C1_strassen = strassen(A, B, counts1_strassen);
    cout << "\nResult (Strassen Multiplication):\n";
    printMatrix(C1_strassen);
    cout << "Strassen Multiply Computations: " << counts1_strassen.multiplications << " multiplications, " << counts1_strassen.additions << " additions.\n";

    cout << "\nComparison result: ";
    compareMatrices(C1_normal, C1_strassen);

    cout << "\n----------------------------\n\n";

    // -------- Example 2: 8x8 random --------
    int n = 8;
    vector<vector<int>> X(n, vector<int>(n));
    vector<vector<int>> Y(n, vector<int>(n));

    // Fill matrices with random numbers (0-9)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            X[i][j] = rand() % 10;
            Y[i][j] = rand() % 10;
        }
    }

    cout << "=== Example 2: 8x8 Random ===\n";
    cout << "Matrix X:\n"; printMatrix(X);
    cout << "Matrix Y:\n"; printMatrix(Y);

    ComputationCounts counts2_normal = {0, 0};
    auto C2_normal = normalMultiply(X, Y, counts2_normal);
    cout << "\nResult (Normal 8x8):\n";
    printMatrix(C2_normal);
    cout << "Normal Multiply Computations: " << counts2_normal.multiplications << " multiplications, " << counts2_normal.additions << " additions.\n";

    ComputationCounts counts2_strassen = {0, 0};
    auto C2_strassen = strassen(X, Y, counts2_strassen);
    cout << "\nResult (Strassen 8x8):\n";
    printMatrix(C2_strassen);
    cout << "Strassen Multiply Computations: " << counts2_strassen.multiplications << " multiplications, " << counts2_strassen.additions << " additions.\n";

    cout << "\nComparison result: ";
    compareMatrices(C2_normal, C2_strassen);

    // -------- Example 3: Larger matrix (e.g., 64x64) for theoretical counts --------
    // Note: Running Strassen on very large matrices directly can be slow due to overhead.
    // This example focuses on demonstrating the count accumulation.
    // For actual performance comparison on large matrices, optimizations are crucial.
    int large_n = 64; // You can increase this, but it will take longer
    cout << "\n=== Example 3: " << large_n << "x" << large_n << " (for theoretical counts) ===\n";

    // Creating dummy matrices of size large_n x large_n
    // We don't need to fill them with actual values for just counting operations
    vector<vector<int>> DummyA(large_n, vector<int>(large_n, 1));
    vector<vector<int>> DummyB(large_n, vector<int>(large_n, 1));

    ComputationCounts counts3_normal = {0, 0};
    normalMultiply(DummyA, DummyB, counts3_normal); // Only run to count operations
    cout << "Theoretical Computations (Normal " << large_n << "x" << large_n << "): " << counts3_normal.multiplications << " multiplications, " << counts3_normal.additions << " additions.\n";

    ComputationCounts counts3_strassen = {0, 0};
    strassen(DummyA, DummyB, counts3_strassen); // Only run to count operations
    cout << "Theoretical Computations (Strassen " << large_n << "x" << large_n << "): " << counts3_strassen.multiplications << " multiplications, " << counts3_strassen.additions << " additions.\n";


    return 0;
}
