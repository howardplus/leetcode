/*
 * https://leetcode.com/problems/insertion-sort-list/description/
 * 
 * Sort a linked list using insertion sort.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insert(ListNode *head, ListNode *nInsert) {

        if (!head || nInsert->val < head->val) {
            nInsert->next = head;
            head = nInsert;
            return head;
        }

        ListNode *prev = nullptr;
        for (ListNode *n=head; n; n=n->next) {
            if (n->val > nInsert->val) {
                if (prev)
                    prev->next = nInsert;
                else
                    head = nInsert;
                nInsert->next = n;
                return head;
            }
            prev = n;
        }

        // not found, add to tail
        prev->next = nInsert;
        nInsert->next = nullptr;

        return head;
    }

    void print(ListNode *head) {
        for (ListNode *n=head; n; n=n->next) {
            cout << n->val << "->";
        }
        cout << "null" << endl;
    }

    ListNode* insertionSortList(ListNode* head) {
        unordered_map<ListNode*, bool> m;

        ListNode *prev = nullptr;
        ListNode *n = head;
        while (n) {
            if (m.find(n) == end(m)) {
                m[n] = true;
                if (prev)
                    prev->next = n->next;
                else
                    head = n->next;
                n->next = nullptr;

                head = insert(head, n);
                prev = nullptr;
                n = head;
            } else {
                prev = n;
                n = n->next;
            }
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

    head = s.insertionSortList(head);    
    s.print(head);
    }

    {
    ListNode *head = new ListNode{-1};
    ListNode *n = head->next = new ListNode{5};
    n = n->next = new ListNode{3};
    n = n->next = new ListNode{4};
    n = n->next = new ListNode{0};

    head = s.insertionSortList(head);    
    s.print(head);
    }

    return 0;
}
