/*
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *n1 = head, *prev = nullptr;
        while (n1) {
            m--;
            n--;
            ListNode *next = n1->next;

            // start reverse
            if (m == 0) {
                ListNode *x = n1, *y = n1->next, *z = n1;
                
                while (y != nullptr && (n-- > 0)) {
                    z = y;
                    y = y->next;
                    z->next = x;
                    x = z;
                }
                
                // next should point to next of block
                next = y;
                if (prev == nullptr)
                    head = z;
                else
                    prev->next = z;
                n1->next = y;
            }

            prev = n1;
            n1 = next;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
/*
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
*/

    Solution s;
    ListNode *head1 = s.reverseBetween(head, 1, 1);

    for (ListNode *n = head1; n; n = n->next) {
        cout << n->val << "->";
    }
    cout << "null" << endl;

    return 0;
}
