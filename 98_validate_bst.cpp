/*
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 */

#include <iostream>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBSTHelper(TreeNode *n, bool use_max, int &val)
    {
        int left, right;
        if (n->left) {
            if (!isValidBSTHelper(n->left, true, left))
                return false;
        } else {
            left = n->val;
        }

        if (n->right) {
            if (!isValidBSTHelper(n->right, false, right))
                return false;
        } else {
            right = n->val;
        }

        if ((n->right && right <= n->val) ||
            (n->left && left >= n->val))
            return false;

        if (use_max)
            val = right;
        else
            val = left;

        return true;
    }

    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr)
            return true;
        int val = 0;
        return isValidBSTHelper(root, false, val);
    }
};

int main()
{
    Solution s;

#if 0
    TreeNode *t1 = new TreeNode(2);
    t1->left = new TreeNode(1);
    t1->right = new TreeNode(3);
    
    cout << s.isValidBST(t1) << endl;
    
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    cout << s.isValidBST(t2) << endl;

    TreeNode *t3 = new TreeNode(1);
    t3->left = new TreeNode(1);
    t3->right = NULL;

    cout << s.isValidBST(t3) << endl;
#endif

    TreeNode *t4 = new TreeNode(10);
    t4->left = new TreeNode(5);
    t4->right = new TreeNode(15);
    t4->right->left = new TreeNode(6);
    t4->right->right = new TreeNode(20);

    cout << s.isValidBST(t4) << endl;

    return 0;
}
