/*
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // at least 2 elements
        ListNode *odd = head, *even = head->next;
        ListNode *even_head = even;
        ListNode *odd_last = head, *even_last = even_head;
        while (odd && even) {
            ListNode *odd_next = even->next;
            ListNode *even_next = nullptr;
            if (odd_next)
                even_next = odd_next->next;

            odd->next = odd_next;
            even->next = even_next;
            odd = odd_next;
            even = even_next;
            if (odd)
                odd_last = odd;
            if (even)
                even_last = even;
        }

        odd_last->next = even_head; 
        even_last->next = nullptr;
                
        return head;
    }
};

int main() {
    Solution s;

    ListNode *head = new ListNode(1);
    ListNode *n = head->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(5);

    head = s.oddEvenList(head);

    for (n=head; n; n=n->next) {
        cout << n->val << "->";
    } 
    cout << "null" << endl;
    
    head = new ListNode(2);
    n = head->next = new ListNode(1);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(5);
    n = n->next = new ListNode(6);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(7);

    head = s.oddEvenList(head);

    for (n=head; n; n=n->next) {
        cout << n->val << "->";
    } 
    cout << "null" << endl;

    return 0;
}
