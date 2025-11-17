#include "JosephusList.h"
#include <stdexcept>

void JosephusList::createList(int n) {
    if (n <= 0) return;

    head = std::make_shared<Node>(1);
    head->next = head;

    auto curr = head;

    for (int i = 2; i <= n; i++) {
        curr->next = std::make_shared<Node>(i);
        curr = curr->next;
    }

    curr->next = head;  // make circular
}

int JosephusList::solve() {
    if (!head) throw std::runtime_error("List is empty.");

    auto p = head;

    while (p->next != p) {
        p->next = p->next->next;  // delete next logically
        p = p->next;              // jump
    }

    return p->data;
}
