#include <iostream>

int fibonachi(int n) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    return fibonachi(n-1) + fibonachi(n-2);
}

int main() {
    int a = 6;
    int f = fibonachi(a);
    std::cout << "fibonachi for number " << a << " = " << f << std::endl;
    return 0;
}
