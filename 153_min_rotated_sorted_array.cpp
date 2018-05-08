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
 * You may assume no duplicate exists in the array.
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
        int prev = -1;
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

    vector<int> t1{4,5,6,7,0,1,2};
    cout << s.findMin(t1) << endl;

    return 0;
}
