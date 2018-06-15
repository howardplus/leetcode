/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
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
    void buildPath(TreeNode *n, TreeNode *target, vector<TreeNode*>& path) {
        path.push_back(n);
        if (n->val == target->val)
            return;
        else if (n->val < target->val)
            buildPath(n->right, target, path);
        else
            buildPath(n->left, target, path);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // find the node p and q, and keep track of the path
        vector<TreeNode*> pPath, qPath;
        buildPath(root, p, pPath);
        buildPath(root, q, qPath);
                
        // compare p_path and q_path, find the last common value
        TreeNode *last = nullptr;
        for (auto i=0; i<min(pPath.size(), qPath.size()); i++) {
            TreeNode *np = pPath[i]; 
            TreeNode *nq = qPath[i];
            if (np != nq)
                return last;
            last = np;
        }

        return last;
    }
};

int main() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution s;

    TreeNode *n;
    n = s.lowestCommonAncestor(root, root->left, root->right);
    cout << n->val << endl;
     
    n = s.lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << n->val << endl;

    n = s.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << n->val << endl;

    n = s.lowestCommonAncestor(root, root->left->left, root->right->left);
    cout << n->val << endl;

    return 0;
}
