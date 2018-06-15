/*
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
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
    int traverse(TreeNode* n, bool &balanced) {
        if (n == nullptr)
            return 0;

        int left = traverse(n->left, balanced); 
        int right = traverse(n->right, balanced);

        int diff = left-right;
        if (diff > 1 || diff < -1)
            balanced = false;

        return (left > right ? left+1 : right+1);
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        traverse(root, balanced);
        return balanced;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.isBalanced(root) << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    cout << s.isBalanced(root) << endl;

    return 0;
}
