#include "BSTKthLargest.h"

int main() {
    /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
    */

    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    kthLargest(root, 4);   // prints the 4th largest

    freeTree(root);
    return 0;
}
