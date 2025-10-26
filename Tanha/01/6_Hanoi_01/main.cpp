#include <iostream>
using namespace std;

int moveCount = 0; // a counter for every move

void hanoiTower(int n, char fromPeg, char toPeg, char auxPeg) {
    if (n == 1) {
        cout << ++moveCount << ". Move disk 1 from " << fromPeg << " to " << toPeg << endl;
        return;
    }
    hanoiTower(n - 1, fromPeg, auxPeg, toPeg);
    cout << ++moveCount << ". Move disk " << n << " from " << fromPeg << " to " << toPeg << endl;
    hanoiTower(n - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int n = 3; // number of disks
    hanoiTower(n, 'A', 'C', 'B');
    cout << "Verification of code: The number of moves should be 2^" <<
        n << " - 1" << endl;
    return 0;
}
