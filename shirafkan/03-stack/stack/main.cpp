#include <iostream>
using namespace std;

struct Stack {
    int a[10];
    int top;
};

// initialize stack
void create(Stack &s) {
    s.top = -1;
}

bool isFull(const Stack &s) {
    return s.top == 9;
}

bool isEmpty(const Stack &s) {
    return s.top == -1;
}

void push(Stack &s) {
    int x;
    cout << "Enter: ";
    cin >> x;

    if (isFull(s))
        cout << "FULL" << endl;
    else {
        s.top++;
        s.a[s.top] = x;
    }
}

void pop(Stack &s) {
    if (isEmpty(s))
        cout << "\nEMPTY\n";
    else {
        cout << "pop = " << s.a[s.top] << endl;
        s.top--;
    }
}

int main() {
    Stack st;
    create(st);

    push(st);
    push(st);
    push(st);

    pop(st);
    pop(st);
    pop(st);
    return 0;
}
