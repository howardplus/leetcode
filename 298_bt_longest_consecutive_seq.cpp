/*
 * Given a binary tree, find the length of the longest consecutive sequence
 * path.
 *
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent child connection. The longest consecutive path
 * need to be from parent to child (cannot be the reverse).
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traverse(TreeNode* n, int tracker, int max_running, int& max_so_far) {
        // leaf node
        if (!n->left && !n->right) {
            max_so_far = max(max_running, max_so_far);
            return;
        }

        // break consecutive seq.
        if (tracker != n->val - 1) {
            max_so_far = max(max_running-1, max_so_far);
            max_running = 1;
        }

        if (n->left) {
            traverse(n->left, n->val, max_running+1, max_so_far);
        }

        if (n->right) {
            traverse(n->right, n->val, max_running+1, max_so_far);
        }
    }

    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;

        int max_so_far = 0;
        traverse(root, INT32_MAX, 1, max_so_far);
        return max_so_far;
    }
};

int main() {
    Solution s;

    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(1);

    cout << s.longestConsecutive(root) << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->left = new TreeNode(6);

    cout << s.longestConsecutive(root) << endl;

    cout << s.longestConsecutive(nullptr) << endl;

    return 0;
}
