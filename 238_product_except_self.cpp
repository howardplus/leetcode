/*
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto tbl = vector<vector<int>>{nums.size(), vector<int>{nums.size(), 1}};
        
    }
};

int main()
{
    Solution s;
    auto t1 = vector<int>{1,2,3,4};
    auto r1 = s.productExceptSelf(t1);
    for (auto i: r1)
        cout << i << endl;

    return 0;
}
