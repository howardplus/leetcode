/*
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * Note:
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int sum = 0, count = 0;
        unordered_map<int, int> m; /* running sum -> # */

        m[0] = 1; /* always 1 running sum of 0 */
        for (const auto &n : nums) {
            sum += n; 
            if (m.find(sum-k) != m.end())
                count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution s;

    vector<int> t1{1,1,1,2,7,7,8,1,-1,1};
    cout << s.subarraySum(t1, 16) << endl;

    vector<int> t2{1,1,1};
    cout << s.subarraySum(t2, 2) << endl;

    return 0;
}
