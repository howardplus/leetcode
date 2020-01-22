#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *first = head, *second = head;

        if (head == NULL)
            return head;

        int cnt = 0;
        while (cnt < k && first->next != NULL) {
            first = first->next;
            cnt++;
        }
        cnt++;

        if (cnt <= k) {
            int kk = k % cnt;
            if (kk == 0)
                return head;

            int ahead = cnt - kk - 1;
            while (ahead) {
                second = second->next;
                ahead--;
            }
        } else {
            while (first->next) {
                first = first->next;
                second = second->next;
            }
        }

        first->next = head;
        head = second->next;
        second->next = NULL;

        return head;
    }

	void print(ListNode* head) {
		while (head) {
			cout << head->val << " -> ";
			head = head->next;	
		}
		cout << "NULL" << endl;
	}
};

int main() {
	Solution s;

	ListNode *l, *tmp;
	tmp = l = new ListNode{1};
	tmp = tmp->next = new ListNode{2};
	tmp = tmp->next = new ListNode{3};
	tmp = tmp->next = new ListNode{4};
	tmp = tmp->next = new ListNode{5};

	s.print(l);	
    ListNode *l1 = s.rotateRight(l, 6);
	s.print(l1);	

    return 0;
}
