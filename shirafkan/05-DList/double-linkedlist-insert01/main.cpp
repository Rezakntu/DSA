#include "DoublyLinkedList.h"
#include <iostream>

int main()
{
    DoublyLinkedList dll;
    int choice, value, pos;

    while (true)
    {
        std::cout << "\n1. Push Back\n";
        std::cout << "2. Push Front\n";
        std::cout << "3. Insert After Position\n";
        std::cout << "4. Show\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter (1..5): ";

        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << "Value: ";
            std::cin >> value;
            dll.push_back(value);
            break;

            case 2:
                std::cout << "Value: ";
            std::cin >> value;
            dll.push_front(value);
            break;

            case 3:
                std::cout << "Value: ";
            std::cin >> value;
            std::cout << "Position: ";
            std::cin >> pos;
            dll.insert_after(pos, value);
            break;

            case 4:
                dll.show();
            break;

            case 5:
                return 0;

            default:
                std::cout << "Invalid.\n";
        }
    }
}
