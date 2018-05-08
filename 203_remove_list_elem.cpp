/*
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * Remove all elements from a linked list of integers that have value val.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *next, *prev = nullptr;
        ListNode *n = head;    
        while (n) {
            next = n->next;

            if (n->val == val) {
                if (prev == nullptr)
                    head = next;
                else
                    prev->next = next;

                delete n;
            } else
                prev = n;

            n = next;
        }
        return head;
    }
};

int main()
    return 0;
}
