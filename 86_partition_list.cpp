/*
 * https://leetcode.com/problems/partition-list/description/
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (!head)
            return head;

        ListNode *h1 = nullptr, *t1 = nullptr, *h2;

        if (head->val < x)
            h1 = head;

        h2 = head;
        while (h2) {
            if (h2->val >= x)
                break;
            t1 = h2;
            h2 = h2->next;
        }

        ListNode *n = h2, *prev = nullptr;
        while (n) {
            auto next = n->next;
            if (n->val < x) {
                if (prev)
                    prev->next = n->next;

                /* append n to t1 */
                n->next = nullptr;
                if (t1)
                    t1->next = n;
                else
                    h1 = n;

                t1 = n;
            } else {
                prev = n;
            }

            n = next;
        }

        if (t1)
            t1->next = h2;

        return h1 ? h1 : h2;
    }

    static void print(ListNode* head)
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

    vector<int> t1 = {1,4,3,2,5,2};
    ListNode *tmp;
    ListNode *root = new ListNode(1);
    tmp = root->next = new ListNode(4);
    tmp = tmp->next = new ListNode(3);
    tmp = tmp->next = new ListNode(2);
    tmp = tmp->next = new ListNode(5);
    tmp = tmp->next = new ListNode(2);

    Solution::print(s.partition(root, 3));

    return 0;
}
