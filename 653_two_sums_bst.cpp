/*
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool search(TreeNode* n, unordered_map<TreeNode*, bool> visited, int val) {
        if (n == nullptr)
            return false;

        if (n->val == val) {
            if (visited.find(n) == end(visited))
                return true;
            else
                return false;
        } else if (n->val < val)
            return search(n->right, visited, val);
        else
            return search(n->left, visited, val);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        // breath-first traversal
        q.push(root);

        while (!q.empty()) {
            // pick a value, remember it
            TreeNode *n = q.front();
            visited[n] = true;
            q.pop();

            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);

            // binary search from root        
            if (search(root, visited, k - n->val))
                return true;
        }

        return false;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << s.findTarget(root, 9) << endl;
    cout << s.findTarget(root, 28) << endl;

    return 0;
}
