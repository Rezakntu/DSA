#include "ExpressionTree.h"

int main() {
    const std::string postfix = "ab+cd/*";

    auto root = ExpressionTree::buildFromPostfix(postfix);

    ExpressionTree::inorder(root.get());
    std::cout << "\n";
}
