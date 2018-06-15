/*
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
    void traverse(TreeNode *n, int level, vector<vector<int>>& result) {
        if (n == nullptr)
            return;

        // add val to the right level
        if (result.size() > level) {
            result[level].push_back(n->val);
        } else {
            vector<int> v = {n->val};
            result.push_back(v);
        }

        if (n->left)
            traverse(n->left, level+1, result);
        if (n->right)
            traverse(n->right, level+1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        traverse(root, 0, v);
        return v;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto r1 = s.levelOrder(root);
    for (auto i : r1) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}
