/*
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2) return 0;
        
        sort(begin(nums), end(nums));

        int diff = -1, last = -1;
        for (auto n : nums) {
            if (last != -1) {
                int d = n - last;
                if (d > diff)
                    diff = d;
            }
            last = n;
        }

        return diff;
    }
};

int main()
{
    Solution s;
    vector<int> n1{1, 10, 3, 2};
    cout << s.maximumGap(n1) << endl;
    return 0;
}
