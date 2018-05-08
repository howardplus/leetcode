/*
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        unordered_map<RandomListNode*, int> m1; // on old list
        unordered_map<int, RandomListNode*> m2; // on new list
        
        int i = 0;
        RandomListNode *n;
        
        // walk first and make note of ptr -> index
        for (n=head; n; n=n->next) {
            m1[n] = i++;
        } 

        // copy, with old ptr
        i = 0;
        RandomListNode *root = nullptr, *prev = nullptr, *cur;
        for (n=head; n; n=n->next) {
            cur = new RandomListNode{n->label};
            cur->random = n->random;
            m2[i++] = cur;

            if (root == nullptr)
                root = cur;
            else
                prev->next = cur;

            prev = cur;
        }

        // replace random with new list's
        for (n=root; n; n=n->next) {
            if (n->random != nullptr) {
                int idx = m1[n->random];
                n->random = m2[idx];
            }
        }

        return root;
    }
};

int main()
{
    Solution s;

    RandomListNode *root = new RandomListNode{0};
    RandomListNode *n1 = root->next = new RandomListNode{1};
    RandomListNode *n2 = n1->next = new RandomListNode{2};
    n2->random = n1;

    RandomListNode *r1 = s.copyRandomList(root);
    
    return 0;
}
