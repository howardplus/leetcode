/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        auto count = 0;
        auto j = 0;
        auto curr = nums[0];
        for (auto i=0; i<nums.size(); i++) {
            if (nums[i] != curr) {
                curr = nums[i];
                count = 0;
            }

            // i is ahead of j
            if (count < 2) {
                if (i != j)
                    nums[j] = nums[i];
                j++;
            }
            count++;
        }
        
        return j;
    }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{1,1,1,2,2,3};
    cout << s.removeDuplicates(t1) << endl;
    for (auto n : t1) {
        cout << n << " ";
    }
    cout << endl;
    
    auto t2 = vector<int>{0,0,1,1,1,1,2,3,3};
    cout << s.removeDuplicates(t2) << endl;
    for (auto n : t2) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
