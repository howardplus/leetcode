#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;

        int mid = (l+r)/2;
        TreeNode *n = new TreeNode{nums[mid]};
        n->left = construct(nums, l, mid-1);
        n->right = construct(nums, mid+1, r);
        return n;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;

        return construct(nums, 0, nums.size()-1);
    }

    void print(TreeNode *n) {
        if (n->left)
            print(n->left);
        cout << n->val << " ";
        if (n->right)
            print(n->right);
    }
};

int main() {

    Solution s;

    vector<int> t{-10,-3,0,5,9};

    TreeNode *r = s.sortedArrayToBST(t);

    s.print(r);

    return 0;
}
