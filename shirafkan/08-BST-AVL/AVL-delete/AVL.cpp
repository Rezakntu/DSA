#include "AVL.h"
#include <iostream>
#include <algorithm>

int AVL::height(const std::shared_ptr<Node>& n) const {
    return n ? n->height : 0;
}

void AVL::updateHeight(const std::shared_ptr<Node>& n) {
    if (n) n->height = 1 + std::max(height(n->left), height(n->right));
}

int AVL::balanceFactor(const std::shared_ptr<Node>& n) const {
    return n ? height(n->left) - height(n->right) : 0;
}

std::shared_ptr<AVL::Node> AVL::rightRotate(std::shared_ptr<Node> y) {
    auto x = y->left;
    auto T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

std::shared_ptr<AVL::Node> AVL::leftRotate(std::shared_ptr<Node> x) {
    auto y = x->right;
    auto T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

std::shared_ptr<AVL::Node> AVL::insertNode(std::shared_ptr<Node> node, int key) {
    if (!node) return std::make_shared<Node>(key);

    if (key < node->data)
        node->left = insertNode(node->left, key);
    else if (key > node->data)
        node->right = insertNode(node->right, key);
    else // equal keys not allowed
        return node;

    updateHeight(node);

    int bf = balanceFactor(node);

    // LL
    if (bf > 1 && key < node->left->data)
        return rightRotate(node);

    // RR
    if (bf < -1 && key > node->right->data)
        return leftRotate(node);

    // LR
    if (bf > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (bf < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

std::shared_ptr<AVL::Node> AVL::minValueNode(std::shared_ptr<Node> node) const {
    auto cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

std::shared_ptr<AVL::Node> AVL::removeNode(std::shared_ptr<Node> node, int key) {
    if (!node) return node;

    if (key < node->data)
        node->left = removeNode(node->left, key);
    else if (key > node->data)
        node->right = removeNode(node->right, key);
    else {
        // node with one or no child
        if (!node->left || !node->right) {
            auto temp = node->left ? node->left : node->right;
            if (!temp) {
                // no child
                return nullptr;
            } else {
                // one child
                node = temp;
            }
        } else {
            // two children: get inorder successor
            auto temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }

    if (!node) return node;

    updateHeight(node);
    int bf = balanceFactor(node);

    // LL
    if (bf > 1 && balanceFactor(node->left) >= 0)
        return rightRotate(node);

    // LR
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RR
    if (bf < -1 && balanceFactor(node->right) <= 0)
        return leftRotate(node);

    // RL
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVL::insert(int key) {
    root = insertNode(root, key);
}

void AVL::remove(int key) {
    root = removeNode(root, key);
}

void AVL::preorderNode(const std::shared_ptr<Node>& n) const {
    if (!n) return;
    std::cout << n->data << " ";
    preorderNode(n->left);
    preorderNode(n->right);
}

void AVL::preorder() const {
    preorderNode(root);
    std::cout << '\n';
}
