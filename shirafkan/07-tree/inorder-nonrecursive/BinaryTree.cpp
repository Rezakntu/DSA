#include "BinaryTree.h"

std::unique_ptr<BinaryTree::Node> BinaryTree::create(int value) {
    return std::make_unique<Node>(value);
}

void BinaryTree::inorderNonRecursive(const std::unique_ptr<Node>& root) const {
    std::stack<Node*> st;
    Node* current = root.get();

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left.get();
        }

        current = st.top();
        st.pop();

        std::cout << current->data << " ";

        current = current->right.get();
    }
}
