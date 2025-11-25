#pragma once
#include <vector>
#include <limits>
#include <functional>
#include <cstddef> // size_t

// Minimal, modern OOP Fibonacci Heap (integer keys).
// - Class owns all nodes and deallocates them in destructor.
// - Typical complexities:
//   * insert, merge: O(1) amortized
//   * find-min: O(1)
//   * extract-min: O(log n) amortized (consolidation)
//   * decrease-key: O(1) amortized (with cuts)
//   * delete: O(log n) amortized (decrease to -inf, then extract)
class FibonacciHeap {
public:
    // Node is public so client can keep references (for decrease_key/delete)
    struct Node {
        int key;
        int degree = 0;
        bool mark = false;
        Node* parent = nullptr;
        Node* child = nullptr;
        Node* left = nullptr;   // circular doubly-linked ring
        Node* right = nullptr;
        explicit Node(int k) : key(k) { left = right = this; }
    };

    FibonacciHeap();
    ~FibonacciHeap();

    // Non-copyable, movable
    FibonacciHeap(const FibonacciHeap&) = delete;
    FibonacciHeap& operator=(const FibonacciHeap&) = delete;
    FibonacciHeap(FibonacciHeap&&) noexcept;
    FibonacciHeap& operator=(FibonacciHeap&&) noexcept;

    // Core API
    Node* insert(int key);               // returns pointer to inserted node
    Node* minimum() const noexcept;      // pointer to min node or nullptr
    bool empty() const noexcept;

    Node* merge(FibonacciHeap&& other);  // merges 'other' into this; returns new min (this)
    Node* extract_min();                 // removes and returns pointer to min (caller must not delete it)
    void decrease_key(Node* x, int new_key);
    void delete_key(Node* x);

    // Utilities
    size_t size() const noexcept { return n_; }

private:
    Node* min_ = nullptr;      // pointer to min root
    size_t n_ = 0;             // number of nodes

    // Internal helpers
    void link(Node* y, Node* x);              // make y a child of x (used in consolidate)
    void consolidate();
    void cut(Node* x, Node* y);
    void cascading_cut(Node* y);

    // helpers for ring insertion/removal
    static void insert_into_root_list(Node*& root, Node* node); // insert node into root list (before root)
    static void remove_from_ring(Node* node);                  // unlink node from its ring

    // destructor helpers
    void delete_all_roots();                 // delete all nodes reachable from root list
    static void delete_subtree(Node* root);  // recursively delete a root's tree (handles rings carefully)

    // estimate of max degree for consolidation: floor(log2(n)) + 1
    static size_t max_degree(size_t n) {
        size_t d = 0;
        while ((static_cast<size_t>(1) << d) <= n) ++d;
        return d + 2; // a little padding
    }
};
