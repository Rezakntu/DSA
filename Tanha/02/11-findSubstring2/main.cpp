#include <iostream>
#include <cstring>  // for strlen
using namespace std;

int subFind2(char *T, char *P) {
    int start = 0;
    int lastT = strlen(T) - 1;
    int lastP = strlen(P) - 1;
    int endmatch = lastP;

    while (endmatch <= lastT) {
        if (T[endmatch] == P[lastP]) {
            int i = start;
            int j = 0;
            while (j <= lastP && T[i] == P[j]) {
                i++;
                j++;
            }
            if (j > lastP)
                return start; // full match found
        }
        endmatch++;
        start++;
    }
    return -1; // not found
}

int main() {
    char text[] = "computerprogramming";
    char pattern[] = "program";

    int pos = subFind2(text, pattern);
    if (pos != -1)
        cout << "Substring found at index " << pos << endl;
    else
        cout << "Substring not found." << endl;

    return 0;
}
