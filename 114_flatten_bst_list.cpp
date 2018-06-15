/*
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
    1
   / \
  2   5
 / \   \
3   4   6

 * to
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */

#include <iostream>
#include <vector>
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
    void traverse(TreeNode *n, queue<TreeNode*>& q) {
        if (n == nullptr)
            return;

        q.push(n);
        traverse(n->left, q);
        traverse(n->right, q);
    }

    void flatten(TreeNode* root) {
        // pre-order traverse            
        queue<TreeNode*> q;
        traverse(root, q); 

        // create list from q
        TreeNode *prev = nullptr;
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            n->left = nullptr;
            n->right = nullptr;
            if (prev)
                prev->right = n;
            prev = n;
        }
    }
};

int main()
{
    Solution s;
    
    TreeNode *root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->left->left = new TreeNode{3};
    root->left->right = new TreeNode{4};
    root->right = new TreeNode{5};
    root->right->right = new TreeNode{6};

    s.flatten(root);

    for (TreeNode *n = root; n; n = n->right) {
        cout << n->val << endl;
    }

    return 0;
}
