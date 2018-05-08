/*
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if (nums.size() <= 1)
            return;
        
        auto sz = nums.size();
        auto j = 0;
        for (auto i = 0; i < sz; i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        
        for (auto i = j; i < sz; i++) {
            nums[i] = 0;
        }
    }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{0, 1, 0, 3, 12};
    s.moveZeroes(t1);
    for (auto i: t1)
        cout << i << endl;

    return 0;
}
