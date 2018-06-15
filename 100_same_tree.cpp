/*
 * https://leetcode.com/problems/same-tree/description/
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 *
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p && q) return false;
        else if (p && !q) return false;
        
        // neither is nullptr
        if (p->val != q->val)
            return false;
        
        auto left = isSameTree(p->left, q->left);
        if (!left)
            return false;
        
        auto right = isSameTree(p->right, q->right);
        if (!right)
            return false;
        
        return true;
    }
};

int main()
{
    return 0;
}
