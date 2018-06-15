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
        ListNode *next, *prev = nullptr;
        ListNode *n = head;
        while (n) {
            next = n->next;
            if (n->val == val) {

                if (prev)
                    prev->next = next;
                else
                    head = next;

                delete n;
            } else {
                prev = n;
            }
            n = next;
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
