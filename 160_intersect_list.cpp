/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        if (a == nullptr || b == nullptr)
            return nullptr;

        bool a_done = false, b_done = false;
        while (true) {
            if (!a_done && a == nullptr) {
                a = headB;
                a_done = true;
            }

            if (!b_done && b == nullptr) {
                b = headA;
                b_done = true;
            }

            if (a == b)
                return a;

            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode *a = new ListNode(1);
    ListNode *tmp = a->next = new ListNode(2);
    ListNode *x = tmp = tmp->next = new ListNode(3);
    tmp = tmp->next = new ListNode(4);

    ListNode *b = new ListNode(5);
    tmp = b->next = new ListNode(6);
    tmp = tmp->next = new ListNode(7);
    //tmp->next = x;

    Solution s;
    ListNode *y =  s.getIntersectionNode(a, b);
    if (y)
        cout << y->val << endl;
    else
        cout << "null" << endl;

    return 0;
}

