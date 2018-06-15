/*
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int v1, v2;
        ListNode *n = nullptr;
        ListNode *head = nullptr;

        while (l1 || l2) {
            if (l1 == nullptr)
                v1 = INT32_MAX;
            else
                v1 = l1->val;

            if (l2 == nullptr)
                v2 = INT32_MAX;
            else
                v2 = l2->val;

            /* pick smaller of the two and advance */
            if (v1 <= v2) {
                if (n) {
                    n->next = l1;
                } else {
                    head = l1;
                }
                n = l1;
                l1 = l1->next;
            } else {
                if (n) {
                    n->next = l2;
                } else {
                    head = l2;
                }
                n = l2;
                l2 = l2->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);

    ListNode *h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(6);
/*
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);
    h1->next->next = new ListNode(5);

    ListNode *h2 = new ListNode(3);
    h2->next = new ListNode(8);
    h2->next->next = new ListNode(9);
*/

    Solution s;
    ListNode *r1 = s.mergeTwoLists(h1, h2);

    for (ListNode *n = r1; n; n=n->next)
        cout << n->val << "->";
    cout << "null" << endl;

    return 0;
}
