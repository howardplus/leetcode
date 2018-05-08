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
        ListNode *d1 = nullptr, *dummy = nullptr;

        ListNode *n = head, *prev = nullptr;
        ListNode *output = nullptr;

        while (n) {
            ListNode *next = n->next;
            if (n->val >= x) {
                if (prev)
                    prev->next = n->next;

                // put in dummy list
                n->next = nullptr;
                if (d1 != nullptr)
                    d1->next = n;
                else
                    dummy = n;
                d1 = n;
            } else {
                prev = n;
                if (output == nullptr)
                    output = n;
            }

            n = next;
        }

        if (dummy != nullptr) {
            if (output == nullptr)
                output = dummy;
            else 
                if (prev)
                    prev->next = dummy;
        }

        return output;
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
