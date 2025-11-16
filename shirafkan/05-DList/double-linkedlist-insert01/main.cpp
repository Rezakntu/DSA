#include "DoublyLinkedList.h"
#include <iostream>

int main() {
    DoublyLinkedList dll;
    int choice, x, pos;

    while (true) {
        std::cout << "\n1. Push Back\n2. Push Front\n3. Insert After Position\n4. Show\n5. Exit\n> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Value: ";
            std::cin >> x;
            dll.push_back(x);
            break;

            case 2:
                std::cout << "Value: ";
            std::cin >> x;
            dll.push_front(x);
            break;

            case 3:
                std::cout << "Value: ";
            std::cin >> x;
            std::cout << "Position: ";
            std::cin >> pos;
            dll.insert_after(pos, x);
            break;

            case 4:
                dll.show();
            break;

            case 5:
                return 0;
        }
    }
}
