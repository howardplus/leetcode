/*
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int traverseUntil(TreeNode *n, int k, int& count)
    {
        int val = 0;
        if (n->left)
            val = traverseUntil(n->left, k, count);

        if (val != 0)
            return val;

        if (++count == k)
            return n->val;

        if (n->right)
            val = traverseUntil(n->right, k, count); 

        if (val != 0)
            return val;

        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;     
        return traverseUntil(root, k, count);
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode{2};
    root->left = new TreeNode{1};
    root->right = new TreeNode{3};

    cout << s.kthSmallest(root, 2) << endl;
    
    root = new TreeNode{8};
    root->left = new TreeNode{5};
    root->left->left = new TreeNode{2};
    root->left->right = new TreeNode{6};
    root->right = new TreeNode{10};

    cout << s.kthSmallest(root, 3) << endl;

    return 0;
}
