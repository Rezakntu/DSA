#include <iostream>
#include <cstring>  // for strlen
using namespace std;

// Function to find all occurrences of pattern P in text T
void naiveStringMatch(char *T, char *P) {
    int n = strlen(T);  // length of text
    int m = strlen(P);  // length of pattern
    bool found = false;

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // Check for match at position i
        while (j < m && T[i + j] == P[j])
            j++;

        // If pattern matched completely
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found in text." << endl;
}

int main() {
    char T[] = "abcabbdef";
    char P[] = "abbd";

    cout << "Text:    " << T << endl;
    cout << "Pattern: " << P << endl;

    naiveStringMatch(T, P);
    return 0;
}
