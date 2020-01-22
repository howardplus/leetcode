/*
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
#include <iostream>
#include <unistd.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode *n = head, *prev = NULL;
		while (n && n->next) {
			auto x = n->next;
			auto y = x->next;	

			n->next = y;
			x->next = n;

			if (prev)
				prev->next = x;
			else
				head = x;

			prev = n;
			n = y;
		}
		return head;
    }

	void print(ListNode *head) {
		while (head) {
			cout << head->val << "->";
			head = head->next;
		}
		cout << "null" << endl;	
	}
};

int main() {
	Solution s;

	ListNode *h = new ListNode{1};
	ListNode *tmp = h;
	tmp = tmp->next = new ListNode{2};
	tmp = tmp->next = new ListNode{3};
	tmp = tmp->next = new ListNode{4};

	auto h1 = s.swapPairs(h);
	s.print(h1);

	return 0;
}
