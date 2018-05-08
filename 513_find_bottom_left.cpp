/*
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxDepth;
    int bottomLeftVal; 

public:
    void traverse(TreeNode *n, int depth)
    {
        if (n->left == nullptr && n->right == nullptr) {
            if (depth >= maxDepth) {
                maxDepth = depth;
                bottomLeftVal = n->val;
            }
            return;
        }

        if (n->right) {
            traverse(n->right, depth+1);
        }
        if (n->left) {
            traverse(n->left, depth+1);
        }
    }

    int findBottomLeftValue(TreeNode* root)
    {
        maxDepth = 0;
        traverse(root, 1);
        return bottomLeftVal;
    }
};

int main()
{
    Solution s;

    TreeNode *r1 = new TreeNode(2);
    r1->left = new TreeNode(1);
    r1->right = new TreeNode(3);

    cout << s.findBottomLeftValue(r1) << endl;

    TreeNode *r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(3);
    r2->left->left = new TreeNode(4);
    r2->right->left = new TreeNode(5);
    r2->right->right = new TreeNode(6);
    r2->right->left->left = new TreeNode(7);

    cout << s.findBottomLeftValue(r2) << endl;

    return 0;
}
