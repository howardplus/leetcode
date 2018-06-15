/*
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; 
        ListNode *n1 = l1;
        ListNode *n2 = l2;

        ListNode *result = nullptr;
        ListNode *n3 = result;

        while (n1 && n2) {
            int sum = n1->val + n2->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else
                carry = 0;

            ListNode *n = new ListNode(sum);
            if (n3 == nullptr) {
                result = n;
            } else {
                n3->next = n;
            }
            n3 = n;

            n1 = n1->next;
            n2 = n2->next;
        }

        // one of n1, n2 is done
        ListNode *n4 = (n1 == nullptr ? n2 : n1);
        while (n4) {
            int sum = n4->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else
                carry = 0;

            ListNode *n = new ListNode(sum);
            n3->next = n;
            n3 = n;

            n4 = n4->next;
        }

        // check leftover carry
        if (carry) {
            n3->next = new ListNode(1);
        }
        
        return result;
    }
};

int main()
{
    ListNode *l1 = new ListNode(5);
/*
    ListNode *n = l1->next = new ListNode(4);
    n = n->next = new ListNode(3);
*/

    ListNode *l2 = new ListNode(5);
/*
    n = l2->next = new ListNode(6);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(1);
*/

    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);

    ListNode *n;
    for (n=result; n; n=n->next) {
        cout << n->val << "->";
    }
    cout << endl;

    return 0;
}
