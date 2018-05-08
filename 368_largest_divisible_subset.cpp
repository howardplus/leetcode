/*
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj
 * % Si = 0.
 *
 * If there are multiple solutions, return any subset is fine.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        vector<int> r;
        vector<int> v(nums.size(), 1);
        vector<int> prev(nums.size(), -1);

        if (nums.size() <= 1)
            return nums;

        sort(begin(nums), end(nums));

        int max_indx = 1;
        for (auto i=1; i<nums.size(); i++) {
            for (auto j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (v[i] < v[j] + 1) {
                        v[i] = v[j]+1;
                        prev[i] = j;
                    }
                }
            }

            if (v[i] > v[max_indx])
                max_indx = i;
        }

        int k = max_indx;
        while (k >= 0) {
            r.push_back(nums[k]);
            k = prev[k];
        }

        return r;
    }
};

int main()
{
    Solution s;

    cout << "test 1" << endl;
    auto t1 = vector<int>{};
    auto r1 = s.largestDivisibleSubset(t1);
    for (auto i : r1)
        cout << i << endl;

    cout << "test 2" << endl;
    auto t2 = vector<int>{1,2,4,8};
    auto r2 = s.largestDivisibleSubset(t2);
    for (auto i : r2)
        cout << i << endl;

    cout << "test 3" << endl;
    auto t3 = vector<int>{2,1,5,8,9};
    auto r3 = s.largestDivisibleSubset(t3);
    for (auto i : r3)
        cout << i << endl;

    cout << "test 4" << endl;
    auto t4 = vector<int>{4,8,10,240};
    auto r4 = s.largestDivisibleSubset(t4);
    for (auto i : r4)
        cout << i << endl;

    return 0;
}
