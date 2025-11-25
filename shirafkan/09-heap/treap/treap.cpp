#include "Treap.h"
#include <iomanip>
#include <cstdlib>

Treap::Treap()
{
    root = nullptr;
}

/* Rotations */
void Treap::rotateLeft(std::unique_ptr<Node>& t)
{
    std::unique_ptr<Node> r = std::move(t->right);
    t->right = std::move(r->left);
    r->left = std::move(t);
    t = std::move(r);
}

void Treap::rotateRight(std::unique_ptr<Node>& t)
{
    std::unique_ptr<Node> l = std::move(t->left);
    t->left = std::move(l->right);
    l->right = std::move(t);
    t = std::move(l);
}

/* Insert */
void Treap::insert(std::unique_ptr<Node>& t, int key)
{
    if (!t)
    {
        t = std::make_unique<Node>(key);
        return;
    }

    if (key < t->key)
    {
        insert(t->left, key);
        if (t->left->priority > t->priority)
            rotateRight(t);
    }
    else if (key > t->key)
    {
        insert(t->right, key);
        if (t->right->priority > t->priority)
            rotateLeft(t);
    }
    // equal key ignored
}

void Treap::insert(int key)
{
    insert(root, key);
}

/* Remove */
void Treap::remove(std::unique_ptr<Node>& t, int key)
{
    if (!t) return;

    if (key < t->key)
        remove(t->left, key);

    else if (key > t->key)
        remove(t->right, key);

    else
    {
        if (!t->left && !t->right)
        {
            t.reset();
        }
        else if (!t->left)
        {
            rotateLeft(t);
            remove(t->left, key);
        }
        else if (!t->right)
        {
            rotateRight(t);
            remove(t->right, key);
        }
        else
        {
            if (t->left->priority < t->right->priority)
            {
                rotateLeft(t);
                remove(t->left, key);
            }
            else
            {
                rotateRight(t);
                remove(t->right, key);
            }
        }
    }
}

void Treap::remove(int key)
{
    remove(root, key);
}

/* Find */
bool Treap::find(const std::unique_ptr<Node>& t, int key) const
{
    if (!t) return false;
    if (t->key == key) return true;
    if (key < t->key)
        return find(t->left, key);
    return find(t->right, key);
}

bool Treap::find(int key) const
{
    return find(root, key);
}

/* Inorder traversal */
void Treap::inorder(const std::unique_ptr<Node>& t) const
{
    if (!t) return;
    inorder(t->left);
    std::cout << t->key << " ";
    inorder(t->right);
}

void Treap::inorder() const
{
    inorder(root);
    std::cout << "\n";
}

/* Display Tree */
void Treap::display(const std::unique_ptr<Node>& t, int level) const
{
    if (!t) return;

    display(t->right, level + 1);
    std::cout << std::setw(level * 6);

    std::cout << t->key << "(" << t->priority << ")\n";
    display(t->left, level + 1);
}

void Treap::display() const
{
    display(root, 1);
    std::cout << "\n";
}
