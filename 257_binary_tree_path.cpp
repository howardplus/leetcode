/*
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void traverse(TreeNode* n, vector<int>& lead, vector<vector<int>>& result) {
        lead.push_back(n->val);

        // at leaf, append val and return
        if (!n->left && !n->right) {
            result.push_back(lead);
            return;
        }

        // depth first traverse
        // make copy for left and right     
        if (n->left) {
            auto left = lead;
            traverse(n->left, left, result);
        }
    
        if (n->right) {
            auto right = lead;
            traverse(n->right, right, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<vector<int>> v;
        if (root == nullptr)
            return result;

        auto lead = vector<int>{};
        traverse(root, lead, v);
        // build it up 
        for (auto path : v) {
            stringstream ss;
            for (auto j=0; j<path.size(); j++) {
                ss << path[j];
                if (j != path.size()-1)
                    ss << "->";
            }
            result.push_back(ss.str()); 
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    auto r1 = s.binaryTreePaths(root);
    for (auto i : r1) {
        cout << i << endl;
    }

    return 0;
}
