/*
 * https://leetcode.com/problems/3sum-closest/
 *
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(begin(nums), end(nums));

		int d = 0;
		for (auto i=0; i<nums.size(); i++) {
			int j = i+1;
			int k = nums.size()-1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == target) {
					return target;
				} else if (sum < target) {
					j++;
				} else {
					k--;
				}

				// track absolute value of difference 
				if (d == 0 ||
					(abs(sum - target) < abs(d)))
					d = target - sum;
			}
		}

		return target - d;
    }
};

int main() {
	Solution s;

	auto t1 = vector<int>{-1, 2, 1, -4};
	cout << s.threeSumClosest(t1, 1) << endl;

	auto t2 = vector<int>{-1, 0, 1, 1, 55};
	cout << s.threeSumClosest(t2, 3) << endl;

    return 0;
}
