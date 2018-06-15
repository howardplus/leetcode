/*
 * https://leetcode.com/problems/two-sum/description/
 *
 * Given an array of integers, return indices of the two numbers such that 
 * they add up to a specific target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (auto i=0; i<nums.size(); i++) {
            int v = target-nums[i];

            if (m.find(v) != end(m)) {
                result.push_back(m[v]);
                result.push_back(i);
                return result;
            }

            m[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {3,2,4};
    auto r1 = s.twoSum(v1, 6);
    for (auto i : r1) {
        cout << i << endl;
    }

    return 0;
}
