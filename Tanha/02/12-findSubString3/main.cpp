#include <iostream>
#include <cstring>
using namespace std;

// Function to build the LPS (Longest Prefix Suffix) array
void computeLPSArray(char* P, int m, int lps[]) {
    int len = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;   // first element is always 0
    int i = 1;

    // Build the LPS array
    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fallback
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP pattern searching
void KMPSearch(char* T, char* P) {
    int n = strlen(T);  // length of text
    int m = strlen(P);  // length of pattern
    int lps[m];

    computeLPSArray(P, m, lps); // Preprocess the pattern

    cout << "Text:    " << T << endl;
    cout << "Pattern: " << P << endl;

    int i = 0; // index for T
    int j = 0; // index for P
    bool found = false;

    while (i < n) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }

        if (j == m) { // full match found
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1]; // continue searching
        } else if (i < n && P[j] != T[i]) { // mismatch
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found in text." << endl;
}

int main() {
    char T[] = "AABAACAADAABAABA";
    char P[] = "AABA";

    KMPSearch(T, P);
    return 0;
}
