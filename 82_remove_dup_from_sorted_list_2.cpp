/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *anchor = nullptr, *prev = nullptr;
        ListNode *r = head;
        bool dup = false;
        while (r) {
            if (r == head) {
                r = r->next;
                prev = head;
                if (r->val != prev->val)
                    anchor = head; 
                continue;
            }


            if (dup && r->val != prev->val) {
                if (anchor == nullptr)
                    head = r;
                else
                    anchor->next = r; 
            }

            if (r->val == prev->val) {
                dup = true;
            }

            prev = r;
            r = r->next;

            if (r->val != prev->val)
                anchor = r;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(1);
    ListNode *n = head->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(5);
    n = n->next = new ListNode(6);

    head = s.deleteDuplicates(head);

    for (n=head; n; n=n->next) {
        cout << n->val << " -> ";
    }
    cout << "null" << endl;
    
    return 0;
}
