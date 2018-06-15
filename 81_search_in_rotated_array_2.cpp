/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;

        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] == target)
                return true;
            else if (nums[idx] > target)
                break;
        }

        for (int idx = nums.size()-1; idx >= 0; idx--) {
            if (nums[idx] == target)
                return true;
            else if (nums[idx] < target)
                break;
        }

        return false;
    }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{2,5,6,0,0,1,2};

    cout << s.search(t1, 0) << endl;
    cout << s.search(t1, 3) << endl;

    auto t2 = vector<int>{1};
    cout << s.search(t2, 0) << endl;

    return 0;
}
