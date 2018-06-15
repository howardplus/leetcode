/*
 * https://leetcode.com/problems/path-sum/description/
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

sum = 22
 *
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
    bool hasPathSum(TreeNode* root, int sum) {
        // depth traversal and if leaf && sum == val, return true       
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;

        bool result = false;
        if (root->left) {
            result = hasPathSum(root->left, sum-root->val);
            if (result)
                return true;
        }
        if (root->right) {
            result = hasPathSum(root->right, sum-root->val);
            if (result)
                return true;
        }

        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4); 
    root->right = new TreeNode(8); 
    root->left->left = new TreeNode(11); 
    root->left->left->left = new TreeNode(7); 
    root->left->left->right = new TreeNode(2); 
    root->right->left = new TreeNode(13); 
    root->right->right = new TreeNode(4); 
    root->right->right->right = new TreeNode(1); 

    Solution s;
    cout << s.hasPathSum(root, 22) << endl; 

    return 0;
}
