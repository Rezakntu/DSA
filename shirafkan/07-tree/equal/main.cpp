#include "Tree.h"

int main()
{
    auto r1 = Node::create(1);
    r1->left        = Node::create(2);
    r1->right       = Node::create(3);
    r1->left->left  = Node::create(4);

    auto r2 = Node::create(1);
    r2->left        = Node::create(2);
    r2->right       = Node::create(3);
    r2->left->left  = Node::create(4);

    if (identical(r1, r2))
        std::cout << "yes\n";
    else
        std::cout << "no\n";

    return 0;
}
