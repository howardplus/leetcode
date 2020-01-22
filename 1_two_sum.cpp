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
        auto m = unordered_map<int, int>{};

        for (int i=0; i<int{nums.size()}; i++) {
            int need = target - nums[i];
            if (m.find(need) != end(m)) {
                return {i, m[need]};
            }
            m[nums[i]] = i;
        }

        // not reached
        return {};
    }
};

int main() {
    Solution s;

    auto v1 = vector<int>{3, 2, 4};
    auto r1 = s.twoSum(v1, 6);
    for (auto i : r1) {
        cout << i << endl;
    }

    auto v2 = vector<int>{2, 7, 11, 15};
    auto r2 = s.twoSum(v2, 9);
    for (auto i : r2) {
        cout << i << endl;
    }
    return 0;
}
