/*
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * Reverse a singly linked list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *n = head;         
        ListNode *prev = nullptr;
        while (n) {
            ListNode *next = n->next;
            n->next = prev;
            prev = n;
            n = next;
        }
        return prev;
    }
};
