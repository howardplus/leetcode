/*
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
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
    void traverse(TreeNode *n, vector<pair<int,int>>& v, int depth) {
        if (n == nullptr)
            return;

        if (n->left)
            traverse(n->left, v, depth+1);

        v.push_back(make_pair(n->val, depth));

        if (n->right)
            traverse(n->right, v, depth+1);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        vector<pair<int,int>> left, right; 
        traverse(root->left, left, 0);
        traverse(root->right, right, 0);

        if (left.size() != right.size())
            return false;

        auto sz = left.size();
        for (auto i=0; i<sz; i++) {
            if (left[i].first != right[sz-i-1].first ||
                left[i].second != right[sz-i-1].second)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode{1};
    TreeNode *n1 = root->left = new TreeNode{2};
    TreeNode *n2 = root->right = new TreeNode{2};
    n1->left = new TreeNode{3};
    n1->right = new TreeNode{4};
    n2->left = new TreeNode{4};
    n2->right = new TreeNode{3};

    cout << s.isSymmetric(root) << endl;

    root = new TreeNode{1};
    n1 = root->left = new TreeNode{2};
    n2 = root->right = new TreeNode{2};
    n1->right = new TreeNode{3};
    n2->right = new TreeNode{3};

    cout << s.isSymmetric(root) << endl;

    root = new TreeNode{1};
    n1 = root->left = new TreeNode{3};
    n2 = root->right = new TreeNode{2};
    n1->right = new TreeNode{2};
    n2->right = new TreeNode{3};

    cout << s.isSymmetric(root) << endl;

    return 0;
}
