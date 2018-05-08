/*
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * Given a complete binary tree, count the number of nodes.
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;  
        if (root == nullptr)
            return count;

        TreeNode *n = root;
        int depth = 0; 
        while (n) {
            depth++;
            n = n->left;
        }

        for (auto i=0; i<depth; i++) {
            if (i == 0)
                count = 1;            
            else {
                int v = 1;
                for (auto j=0; j<i; j++) {
                    v *= 2;
                }
                count += v;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode{2};
    root->left = new TreeNode{1};
    root->right = new TreeNode{1};

    cout << s.countNodes(root) << endl;

    return 0;
}
