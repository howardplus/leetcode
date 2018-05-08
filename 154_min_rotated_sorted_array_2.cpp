/*
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * duplicate may exist in the array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int m = nums[0];
        int prev = m;
        for (auto n : nums) {
            if (n < prev)
                return n;
            prev = n;
        }
        return m;
    }
};

int main()
{
    Solution s;

    vector<int> t1{-9,-8,-7,0,1,2,3,4,5,6,7,8,9,10,10,-10,-9};
    cout << s.findMin(t1) << endl;

    return 0;
}
