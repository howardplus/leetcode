/*
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;

        if (root == nullptr)
            return v;

        queue<pair<TreeNode*,int>> q; /* node with level */
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *n = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (n->left) q.push(make_pair(n->left, lvl+1));
            if (n->right) q.push(make_pair(n->right, lvl+1)); 

            if (v.size() <= lvl) {
                v.push_back(vector<int>{n->val});
            } else {
                v[lvl].push_back(n->val);
            }
        }

        // reverse odd levels
        for (auto i=0; i<v.size(); i++) {
            if (i % 2) {
                auto sz = v[i].size();
                for (auto n=0; n<sz/2; n++) {
                    auto tmp = v[i][n];
                    v[i][n] = v[i][sz-n-1];
                    v[i][sz-n-1] = tmp;
                }
            }    
        }

        return v;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode{3};
    root->left = new TreeNode{9};
    root->right = new TreeNode{20};
    root->right->left = new TreeNode{15};
    root->right->right = new TreeNode{7};

    auto r1 = s.zigzagLevelOrder(root);

    for (auto l : r1) {
        for (auto n : l) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
