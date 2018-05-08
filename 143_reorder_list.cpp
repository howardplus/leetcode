/*
 * https://leetcode.com/problems/reorder-list/description/
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (head == nullptr)
            return;

        ListNode *fast = head;
        ListNode *slow = head;

        // fold it in half
        ListNode *end = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        cout << "mid = " << slow->val << endl;

        // starting from mid point, reverse the linked list
        ListNode *prev = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        };
        end = prev;

        cout << "end = " << end->val << endl;

        Solution s;
        s.print(head);
        s.print(end);

        // alternately insert ends to head
        ListNode *left = head;
        ListNode *right = end;
        while (left && right) {
            cout << "left = " << left->val << "; right = " << right->val << endl;
            ListNode *left_next, *right_next;
            right_next = right->next; 
            left_next = left->next;

            left->next = right;
            if (left_next != right)
                right->next = left_next;

            right = right_next;
            left = left_next;
            this_thread::sleep_for(seconds(1));
        }
        
    }

    void print(ListNode *head)
    {
        while (head) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    Solution s;

    ListNode *root = new ListNode(1);
    /*
    ListNode *tmp = root->next = new ListNode(2);
    tmp = tmp->next = new ListNode(3);
    tmp = tmp->next = new ListNode(4);
    tmp = tmp->next = new ListNode(5);
    */

    s.print(root);
    s.reorderList(root);
    s.print(root);

    return 0;
}
