/*
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int traverse(TreeNode* n, int sum, vector<int> s) {
        if (!n)
            return 0;

        // check sum and continue
        int count = 0;
        if (n->val == sum)
            count++;

        for (auto& i : s) {
            if (n->val == (sum - i))
                count++;
            i += n->val; 
        }

        s.push_back(n->val);
        if (n->left)
            count += traverse(n->left, sum, s);

        if (n->right)
            count += traverse(n->right, sum, s);

        return count;
    }

    int pathSum(TreeNode* root, int sum) {
        vector<int> v;
        return traverse(root, sum, v);
    }
};

int main()
{
    TreeNode *root = new TreeNode{5};
    root->left = new TreeNode{4};
    root->left->left = new TreeNode{11};
    root->left->left->left = new TreeNode{7};
    root->left->left->right = new TreeNode{2};
    root->right = new TreeNode{8};
    root->right->left = new TreeNode{13};
    root->right->right = new TreeNode{4};
    root->right->right->left = new TreeNode{5};
    root->right->right->right = new TreeNode{1};
    
    Solution s;
    cout << s.pathSum(root, 22) << endl;

    return 0;
}
