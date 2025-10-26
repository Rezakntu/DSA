#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10; // maximum number of disks

// Push a disk onto a peg
void push(int peg[], int &top, int disk) {
    peg[++top] = disk;
}

// Pop a disk from a peg
int pop(int peg[], int &top) {
    if (top < 0) return -1; // empty peg
    return peg[top--];
}

// Print the state of all three pegs
void printState(int pegA[], int topA, int pegB[], int topB, int pegC[], int topC, int n) {
    cout << "\nCurrent State of Pegs:\n";
    cout << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
    for (int i = n - 1; i >= 0; i--) {
        // Print peg A
        if (i <= topA) cout << setw(5) << pegA[i];
        else cout << setw(5) << "|";

        // Print peg B
        if (i <= topB) cout << setw(5) << pegB[i];
        else cout << setw(5) << "|";

        // Print peg C
        if (i <= topC) cout << setw(5) << pegC[i];
        else cout << setw(5) << "|";

        cout << endl;
    }
    cout << "-------------------\n";
}

// Move one disk from peg1 to peg2
void moveDisk(int peg1[], int &top1, int peg2[], int &top2, char name1, char name2,
              int pegA[], int topA, int pegB[], int topB, int pegC[], int topC, int n) {
    int disk = pop(peg1, top1);
    push(peg2, top2, disk);
    cout << "\nMove disk " << disk << " from " << name1 << " to " << name2 << endl;
    printState(pegA, topA, pegB, topB, pegC, topC, n);
}

// Recursive Hanoi solver
void hanoiTower(int n,
                int pegA[], int &topA, char nameA,
                int pegB[], int &topB, char nameB,
                int pegC[], int &topC, char nameC, int totalDisks) {
    if (n == 1) {
        moveDisk(pegA, topA, pegC, topC, nameA, nameC, pegA, topA, pegB, topB, pegC, topC, totalDisks);
        return;
    }
    hanoiTower(n - 1, pegA, topA, nameA, pegC, topC, nameC, pegB, topB, nameB, totalDisks);
    moveDisk(pegA, topA, pegC, topC, nameA, nameC, pegA, topA, pegB, topB, pegC, topC, totalDisks);
    hanoiTower(n - 1, pegB, topB, nameB, pegA, topA, nameA, pegC, topC, nameC, totalDisks);
}

int main() {
    int n = 3; // number of disks

    // Initialize pegs
    int pegA[MAX], pegB[MAX], pegC[MAX];
    int topA = -1, topB = -1, topC = -1;

    // Put all disks on pegA (largest at bottom, smallest at top)
    for (int i = n; i >= 1; i--) {
        push(pegA, topA, i);
    }

    cout << "Initial State:\n";
    printState(pegA, topA, pegB, topB, pegC, topC, n);

    cout << "\nTower of Hanoi with " << n << " disks:\n";
    hanoiTower(n, pegA, topA, 'A', pegB, topB, 'B', pegC, topC, 'C', n);

    return 0;
}
