/*
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	int length;
	ListNode *listHead;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
		length = 0;
		listHead = head;
		while (head) {
			length++;
			head = head->next;
		}
    }
    
    /** Returns a random node's value. */
    int getRandom() {
		int n;
		do {
			n = rand();
		} while (n >= (RAND_MAX - RAND_MAX % length));
		n %= length;
		
		ListNode *ln = listHead;
		while (n--) {
			ln = ln->next;	
		}
		return ln->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
int main() {
	ListNode *h1, *tmp;
	tmp = h1 = new ListNode{0};
	tmp = tmp->next = new ListNode{1};
	tmp = tmp->next = new ListNode{2};
	tmp = tmp->next = new ListNode{3};

	Solution obj{h1};
	int param_1 = obj.getRandom();

	cout << param_1 << endl;

	return 0;
}
