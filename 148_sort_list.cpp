/*
 * https://leetcode.com/problems/sort-list/description/
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    void print(ListNode *head) {
        for (ListNode *n=head; n; n=n->next) {
            cout << n->val << "->";
        }
        cout << "null" << endl;
    }

    ListNode* sortList(ListNode* head) {
        // single or nothing 
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // split into 2
        ListNode *n = head, *fast = head;
        while (true) {
            fast = fast->next ? fast->next->next : nullptr;
            if (fast == nullptr) break;
            n = n->next;
        }
        ListNode *n1 = n->next;
        n->next = nullptr;

        ListNode *firstHalf = sortList(head);
        ListNode *secondHalf = sortList(n1);

        // merge first and second half
        n1 = nullptr;
        while (firstHalf || secondHalf) {
            if (!firstHalf) {
                n = secondHalf;
                secondHalf = secondHalf->next;
            } else if (!secondHalf) {
                n = firstHalf;
                firstHalf = firstHalf->next;
            } else {
                if (firstHalf->val < secondHalf->val) {
                    n = firstHalf;
                    firstHalf = firstHalf->next;
                } else {
                    n = secondHalf;
                    secondHalf = secondHalf->next;
                }
            }

            if (n1) {
                n1->next = n;
            } else {
                head = n;
            }

            n1 = n;
        }
        return head;
    }
};

int main()
{
    Solution s;

    {
    ListNode *head = new ListNode{4};
    ListNode *n = head->next = new ListNode{2};
    n = n->next = new ListNode{1};
    n = n->next = new ListNode{3};

    head = s.sortList(head);    
    s.print(head);
    }

    { 
    ListNode *head = new ListNode{-1};
    ListNode *n = head->next = new ListNode{5};
    n = n->next = new ListNode{3};
    n = n->next = new ListNode{4};
    n = n->next = new ListNode{0};

    head = s.sortList(head);    
    s.print(head);
    }

    return 0;
}
