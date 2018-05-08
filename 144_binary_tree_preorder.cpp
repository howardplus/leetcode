/*
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> preorderTraversalHelper(TreeNode *root, vector<int> &v)
    {
        if (root != nullptr) {
            v.push_back(root->val);
            if (root->left)
                preorderTraversalHelper(root->left, v);
            if (root->right)
                preorderTraversalHelper(root->right, v);
        }

        return v;
    }

public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v;
        return preorderTraversalHelper(root, v);
    }
};

int main()
{
    Solution s;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *tmp  = t1->right = new TreeNode(2);
    tmp = tmp->left = new TreeNode(3);

    auto v1 = s.preorderTraversal(t1);

    for (auto v: v1) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
