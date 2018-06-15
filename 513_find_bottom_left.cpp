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

/*
 * To find the bottom left, we use the following strategy:
 * 1. Keep track of the max depth, record the val of leaf node
 *    when current depth is >= max depth.
 * 2. For same depth, left wins. So traverse to the right before
 *    left arm.
 *
 * if root is null, return 0
 */
class Solution {
public:
    void traverse(TreeNode *n, int depth, int& val, int& maxDepth) {
        if (!n->left && !n->right) {
            maxDepth = max(maxDepth, depth);
            if (depth >= maxDepth)
                val = n->val;
            return;
        }

        if (n->right)
            traverse(n->right, depth+1, val, maxDepth);

        if (n->left)
            traverse(n->left, depth+1, val, maxDepth);
    }

    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;

        int maxDepth = 0;
        int val;
        traverse(root, 0, val, maxDepth);
        return val;
    }
};

int main() {
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
