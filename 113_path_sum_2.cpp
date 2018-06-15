/*
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

sum = 22
result = 
    5 4 11 2
    5 8 4 5
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traverse(TreeNode* n, int sum, vector<int> q, vector<vector<int>>& v) {
        // if leaf and sum equal val, then add to vector
        if (n->left == nullptr && n->right == nullptr) {
            if (n->val == sum) {
                q.push_back(n->val);
                v.push_back(q);
            }
            return;
        }

        q.push_back(n->val);
        if (n->left) {
            traverse(n->left, sum - n->val, q, v);
        }

        if (n->right) {
            traverse(n->right, sum - n->val, q, v);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        if (root == nullptr)
            return v;

        traverse(root, sum, vector<int>{}, v);
        return v;
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;

    auto r = s.pathSum(root, 22);
    for (auto i : r) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
