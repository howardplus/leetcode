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
        auto left = vector<int>(nums.size(), 0);
        auto right = vector<int>(nums.size(), 0);
        auto result = vector<int>(nums.size(), 0);

        if (nums.size() == 0)
            return result;

        int p = 1;
        for (auto i=0; i<nums.size(); i++) {
            left[i] = p;
            p *= nums[i]; 
        }

        p = 1;
        for (auto j=0; j<nums.size(); j++) {
            right[nums.size()-j-1] = p;
            p *= nums[nums.size()-j-1];
        }
       
        for (auto i=0; i<nums.size(); i++) {
            result[i] = left[i] * right[i];
        }

        return result;
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
