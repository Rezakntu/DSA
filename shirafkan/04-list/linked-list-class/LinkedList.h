#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

class LinkedList {
public:
    struct Node {
        int data;
        std::unique_ptr<Node> next;
        Node(int d);
    };

    LinkedList();

    // Rule of Five
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept = default;
    LinkedList& operator=(LinkedList&& other) noexcept = default;
    ~LinkedList() = default;

    // Operations
    void add_begin(int value);
    void show() const;
    void delete_all(int value);
    int find_kth(int k) const;
    int middle() const;
    void concat(LinkedList& other);
    int length() const;

    // Big-number subtraction
    static LinkedList subtract(const LinkedList& a, const LinkedList& b);

private:
    std::unique_ptr<Node> head;

    void pad_zeros(int n);

    static std::unique_ptr<Node> subtract_recursive(
        const Node* n1, const Node* n2, bool& borrow);

    static std::unique_ptr<Node> clone_list(
        const std::unique_ptr<Node>& src);
};

#endif
