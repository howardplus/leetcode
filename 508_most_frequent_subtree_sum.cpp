/*
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using SumMap = unordered_map<int, int>;

class Solution {
public:
    int getSum(TreeNode *n, SumMap& sums)
    {
        if (n == nullptr)
            return 0;

        int sum = getSum(n->left, sums) + getSum(n->right, sums) + n->val;
        sums[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        SumMap sm; /* sum + count */
        getSum(root, sm);

        vector<int> r;
        int maxSum = 0;
        for (auto i: sm) {
            if (i.second == maxSum) {
                r.push_back(i.first);
            } else if (i.second > maxSum) {
                maxSum = i.second;
                r.clear();
                r.push_back(i.first);
            }
        }

        return r;
    }
};

int main()
{
    Solution s;

    TreeNode *r1 = new TreeNode(5);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(-3);

    auto v1 = s.findFrequentTreeSum(r1);
    for (auto v : v1)
        cout << v << endl;
    cout << endl; 

    TreeNode *r2 = new TreeNode(5);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(-5);

    auto v2 = s.findFrequentTreeSum(r2);
    for (auto v : v2)
        cout << v << endl;
    cout << endl; 

    return 0;
}
