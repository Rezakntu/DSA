#include "BST.h"
#include <iostream>

void BST::insert(int value) {
    insert(root, value);
}

void BST::insert(std::unique_ptr<Node>& node, int value) {
    if (!node) {
        node = std::make_unique<Node>(value);
        return;
    }

    if (value < node->data)
        insert(node->left, value);
    else
        insert(node->right, value);
}

void BST::findPreSuc(Node* node, Node*& pre, Node*& suc, int key) {
    if (!node) return;

    if (node->data == key) {
        // Predecessor: max in left subtree
        if (node->left) {
            Node* t = node->left.get();
            while (t->right)
                t = t->right.get();
            pre = t;
        }

        // Successor: min in right subtree
        if (node->right) {
            Node* t = node->right.get();
            while (t->left)
                t = t->left.get();
            suc = t;
        }
        return;
    }

    if (key < node->data) {
        suc = node;
        findPreSuc(node->left.get(), pre, suc, key);
    } else {
        pre = node;
        findPreSuc(node->right.get(), pre, suc, key);
    }
}

std::optional<int> BST::predecessor(int key) {
    Node *pre = nullptr, *suc = nullptr;
    findPreSuc(root.get(), pre, suc, key);
    if (pre) return pre->data;
    return std::nullopt;
}

std::optional<int> BST::successor(int key) {
    Node *pre = nullptr, *suc = nullptr;
    findPreSuc(root.get(), pre, suc, key);
    if (suc) return suc->data;
    return std::nullopt;
}
