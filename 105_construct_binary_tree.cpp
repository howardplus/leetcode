/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *     3
      / \
     9  20
       /  \
      15   7
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]); 

        // find root index in inorder
        auto it = find(begin(inorder), end(inorder), root->val);
        auto idx = it - begin(inorder);

        // split to left and right and continue
        int sz = 0;
        if (it != begin(inorder)) {
            auto left = vector<int>(begin(inorder), it);
            auto pleft = vector<int>(begin(preorder)+1, begin(preorder)+1+left.size());
            sz = left.size();
            root->left = buildTree(pleft, left);
        }
        it++;
        if (it != end(inorder)) {
            auto right = vector<int>(it, end(inorder));
            auto pright = vector<int>(begin(preorder)+1+sz, end(preorder));
            root->right = buildTree(pright, right);
        }

        return root;
    }
};

int main()
{
    Solution s;
    auto pre = vector<int>{3,9,20,15,7};
    auto in = vector<int>{9,3,15,20,7};
    auto root = s.buildTree(pre, in);
    return 0;
}
