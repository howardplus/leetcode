/*
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *prev = nullptr, *n = head;

        while (n) {
            if (n->val == val) {
                if (prev)
                    prev->next = n->next;
                else
                    head = n->next;
            } else {
                prev = n;
            }
            n = n->next;
        }

        return head;
    }
};

int main() {

    ListNode *head = new ListNode(3);
    ListNode *n = head->next = new ListNode(1);
    n = n->next = new ListNode(2);
    n = n->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(2);
    n = n->next = new ListNode(1);

    Solution s;
    ListNode *n1 = s.removeElements(head, 3);

    for (ListNode *e = n1; e; e = e->next) {
        cout << e->val << " ";
    }
    cout << endl;
    
    return 0;
}
