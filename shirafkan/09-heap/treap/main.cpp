#include <iostream>
#include "Treap.h"

int main()
{
    Treap t;

    while (true)
    {
        std::cout << "\n--- Treap Menu ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Inorder\n";
        std::cout << "5. Display Tree\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter choice: ";

        int ch, value;
        std::cin >> ch;

        switch (ch)
        {
            case 1:
                std::cout << "Enter value: ";
            std::cin >> value;
            t.insert(value);
            break;

            case 2:
                std::cout << "Enter value: ";
            std::cin >> value;
            t.remove(value);
            break;

            case 3:
                std::cout << "Enter value: ";
            std::cin >> value;
            std::cout << (t.find(value) ? "Found\n" : "Not Found\n");
            break;

            case 4:
                t.inorder();
            break;

            case 5:
                t.display();
            break;

            case 6:
                return 0;

            default:
                std::cout << "Invalid choice\n";
        }
    }
}
