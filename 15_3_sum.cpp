/*
 * https://leetcode.com/problems/3sum/
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int moveRight(const vector<int>& nums, int i, int j) {
		while (i < j && nums[i] == nums[i+1]) i++;
		return i+1;
	}

	int moveLeft(const vector<int>& nums, int i, int j) {
		while (i > j && nums[i] == nums[i-1]) i--;
		return i-1;
	}

    vector<vector<int>> threeSum(vector<int>& nums) {
		auto r = vector<vector<int>>{};
		sort(begin(nums), end(nums));

		for (auto i=0; i<nums.size(); i++) {
			if ((i != 0) && (nums[i] == nums[i-1])) continue;

			auto j=i+1;
			auto k=nums.size()-1;

			while (j < k) {
				auto sum = nums[i] + nums[j] + nums[k];
				if (sum == 0) {
					r.push_back({nums[i], nums[j], nums[k]});
					j = moveRight(nums, j, k);
					k = moveLeft(nums, k, j);
				} else if (sum < 0) {
					j = moveRight(nums, j, k);
				} else {
					k = moveLeft(nums, k, j);
				}
			}
		}

		return r;
    }
};

int main() {
	Solution s;

	auto t1 = vector<int>{-1, 0, 1, 2, -1, -4};
	auto r1 = s.threeSum(t1);

	cout << "[" << endl;
	for (auto i: r1) {
		cout << "[" << endl;
		for (auto j: i) {
			cout << j << " ";			
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	return 0;
}
