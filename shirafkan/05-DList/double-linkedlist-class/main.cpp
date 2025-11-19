#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList dl;
    int choice, x, pos;

    while (true) {
        std::cout << "\n1. Create Node\n"
                     "2. Add at beginning\n"
                     "3. Add after position\n"
                     "4. Delete\n"
                     "5. Display\n"
                     "6. Count\n"
                     "7. Reverse\n"
                     "8. Exit\n"
                     "Enter choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter: ";
            std::cin >> x;
            dl.create_list(x);
            break;

            case 2:
                std::cout << "Enter: ";
            std::cin >> x;
            dl.add(x);
            break;

            case 3:
                std::cout << "Enter: ";
            std::cin >> x;
            std::cout << "Position: ";
            std::cin >> pos;
            dl.add_after(x, pos);
            break;

            case 4:
                std::cout << "Enter: ";
            std::cin >> x;
            dl.delete_node(x);
            break;

            case 5:
                dl.show();
            break;

            case 6:
                dl.count();
            break;

            case 7:
                dl.reverse();
            break;

            case 8:
                return 0;

            default:
                std::cout << "Invalid\n";
        }
    }
}
