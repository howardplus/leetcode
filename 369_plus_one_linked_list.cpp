/*
 * https://leetcode.com/problems/plus-one-linked-list/description/
 *
 * Given a non-negative integer represented as non-empty a singly linked list 
 * of digits, plus one to the integer. 
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 */
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
		stack<ListNode*> s;
		for (auto n=head; n; n=n->next) {
			s.push(n);
		}

		// add one to top element
		s.top()->val++;

		// do carry
		int carry = 0;
		while (!s.empty()) {
			ListNode* n = s.top();
			s.pop();

			n->val += carry;				
			if (n->val == 10) {
				n->val = 0;
				carry = 1;
			} else {
				carry = 0;
				break;
			}
		}

		// add element if carry all the way to the head
		if (carry) {
			auto n = new ListNode(1);	
			n->next = head;
			head = n;
		}

		return head;
    }

	void print(ListNode* head) {
		for (auto n=head; n; n=n->next)
			cout << n->val;
		cout << endl;
	}
};

int main() {
	Solution s;

	/* 123 -> 124 */
	ListNode *h1 = new ListNode(1);
	h1->next = new ListNode(2);
	h1->next->next = new ListNode(3);

	auto s1 = s.plusOne(h1);	

	s.print(s1);

	/* 999 -> 1000 */
	ListNode *h2 = new ListNode(9);
	h2->next = new ListNode(9);
	h2->next->next = new ListNode(9);

	auto s2 = s.plusOne(h2);

	s.print(s2);

	/* 0 -> 1 */
	ListNode *h3 = new ListNode(0);

	auto s3 = s.plusOne(h3);

	s.print(s3);

	return 0;
}
