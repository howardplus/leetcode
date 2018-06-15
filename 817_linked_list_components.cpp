/*
 * https://leetcode.com/problems/linked-list-components/description/
 *
 * We are given head, the head node of a linked list containing unique integer
 * values.
 *
 * We are also given the list G, a subset of the values in the linked list.
 *
 * Return the number of connected components in G, where two values are
 * connected if they appear consecutively in the linked list.
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, const vector<int>& G) {
    }
};

int main()
{
    Solution s;

    ListNode *head1 = new ListNode(0);
    ListNode *n = head1->next = new ListNode(1);
    n = n->next = new ListNode(2);
    n = n->next = new ListNode(3);

    cout << s.numComponents(head1, {0,1,3}) << endl;

    ListNode *head2 = new ListNode(0);
    n = head2->next = new ListNode(1);
    n = n->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(4);

    cout << s.numComponents(head2, {0,3,1,4}) << endl;

    return 0;
}
