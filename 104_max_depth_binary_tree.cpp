/*
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
    int depth(TreeNode *n)
    {
        int left = 0, right = 0;
        if (n->left) {
            left = depth(n->left);
        }
        if (n->right) {
            right = depth(n->right);
        }
        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == NULL) return 0;
        return depth(root);
    }
};

int main()
{
    Solution s;

    TreeNode *r1 = new TreeNode(3);
    TreeNode *tmp = r1->left = new TreeNode(9);
    tmp = r1->right = new TreeNode(20);
    tmp->left = new TreeNode(15);
    tmp->right = new TreeNode(7);

    cout << s.maxDepth(r1) << endl;

    return 0;
}
