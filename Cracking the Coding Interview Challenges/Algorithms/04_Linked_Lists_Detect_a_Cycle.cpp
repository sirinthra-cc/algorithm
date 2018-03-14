/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include<unordered_map>

bool has_cycle_loop(Node* head, unordered_map<Node*, int> &addrs) {
    if (head == nullptr) return false;
    else if (addrs.find(head) != addrs.end()) return true;
    else {
        addrs[head] = 1;
        return has_cycle_loop(head->next, addrs);
    }
}

bool has_cycle(Node* head) {
    if (head == nullptr) return false;
    else {
        unordered_map<Node*, int> addrs;
        addrs[head] = 1;
        return has_cycle_loop(head->next, addrs);
    }
}
