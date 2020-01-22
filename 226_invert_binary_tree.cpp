/*
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * Invert a binary tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right); 

        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode{4};
    root->left = new TreeNode{2};
    root->right = new TreeNode{7};
    root->left->left = new TreeNode{1};
    root->left->right = new TreeNode{3};
    root->right->left = new TreeNode{6};
    root->right->right = new TreeNode{9};

    root = s.invertTree(root);    

    return 0;
}
