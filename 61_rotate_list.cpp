/*
 * https://leetcode.com/problems/rotate-list/description/
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;

        int count = 0;
        for (auto n=head; n; n=n->next)
            count++;

        k %= count;
        k = count-k;
        k %= count;

        /* perfect rotation */
        if (count == 1 || k == 0)
            return head;

        ListNode *prev = nullptr, *newHead, *newTail;
        for (auto n=head; n; n=n->next) {
            if (k == 0) {
                newHead = n;
                newTail = prev;
            }
            k--;        
            prev = n;
        }

        prev->next = head;
        newTail->next = nullptr; 

        return newHead;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode{1};
    ListNode *n = head->next = new ListNode{2}; 
    n = n->next = new ListNode{3}; 
    n = n->next = new ListNode{4}; 
    n = n->next = new ListNode{5}; 

    for (n=head; n; n=n->next) {
        cout << n->val << "->";
    }
    cout << "null" << endl;

    head = s.rotateRight(head, 235026);

    for (n=head; n; n=n->next) {
        cout << n->val << "->";
    }
    cout << "null" << endl;

    return 0;
}
