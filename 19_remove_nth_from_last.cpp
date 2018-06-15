/*
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n1 is ahead of n2 by n 
        ListNode *prev = nullptr, *n1 = head, *n2 = head;
        while (n--) {
            n1 = n1->next;
        }

        while (n1) {
            n1 = n1->next;
            prev = n2;
            n2 = n2->next;
        }

        // remove n2
        if (prev)
            prev->next = n2->next; 
        else
            head = n2->next;
        
        delete n2;

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *n = head->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(5);

    Solution s;
    ListNode *n1 = s.removeNthFromEnd(head, 5);

    for (n=n1; n; n=n->next) {
        cout << n->val << "->";
    }
    cout << endl;

    return 0;
}
