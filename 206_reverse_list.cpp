/*
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * Reverse a singly linked list.
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
    ListNode* reverse(ListNode* n, ListNode*& end) {
        if (n->next == nullptr) {
            end = n;
            return n;
        }

        ListNode *e = nullptr;
        ListNode *h1 = reverse(n->next, e);
        e->next = n;
        n->next = nullptr;
        end = n;
        return h1;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *end;
        return reverse(head, end);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *n = head;
        while (n) {
            ListNode *next = n->next;

            n->next = prev;
            if (next == nullptr)
                head = n;

            prev = n;
            n = next;
        }
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *n = head->next = new ListNode(2);
    n = n->next = new ListNode(3);
    n = n->next = new ListNode(4);
    n = n->next = new ListNode(5);

    Solution s;
    ListNode *h1 = s.reverseList(head);

    for (n=h1; n; n=n->next) {
        cout << n->val << "->";
    }
    cout << "null" << endl;

    return 0;
}
