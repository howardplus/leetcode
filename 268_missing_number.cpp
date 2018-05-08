/*
 * https://leetcode.com/problems/missing-number/description/
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(const vector<int>& nums)
    {
        int sum = 0; 
        for (auto n: nums) {
            sum += n;
        }

        int n = nums.size() +1;
        return (n*(n-1)/2) - sum;
    }
};

int main()
{
    Solution s;

    cout << s.missingNumber(vector<int>{9,6,4,2,3,5,7,0,1}) << endl;

    return 0;
}
