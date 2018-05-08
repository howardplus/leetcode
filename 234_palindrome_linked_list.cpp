/*
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {

        if (head == nullptr)
            return true;

        ListNode *n = head, *mid = head;
     
        auto odd = false;
        while (n && n->next) {
            n = n->next->next;
            mid = mid->next;
            if (n && n->next == nullptr)
                odd = true;
        }

        ListNode *prev = nullptr, *next;
        n = head;
        while (n != mid) {
            next = n->next;
            n->next = prev;
            prev = n;
            n = next;
        }

        if (odd)
            mid = mid->next;
        n = prev;
        while (n) {
            if (n->val != mid->val)
                return false;

            mid = mid->next; 
            n = n->next;
        }

        return true;
    }
};

int main()
{
    Solution s;

    ListNode *root = new ListNode{3};
    ListNode *tmp = root->next = new ListNode{5};
    tmp = tmp->next = new ListNode{6};
    tmp = tmp->next = new ListNode{5};
    tmp = tmp->next = new ListNode{3};

    cout << s.isPalindrome(root) << endl;
    
    return 0;
}
