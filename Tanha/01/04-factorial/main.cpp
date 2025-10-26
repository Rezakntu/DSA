#include <iostream>
using namespace std;

int factorial(int f) {
    if(f == 0) return 1;
    return f * factorial(f-1);
}

int main() {
    int f = 4;
    int a = factorial(f);
    std::cout << f << "! = " << a << std::endl;
    return 0;
}
