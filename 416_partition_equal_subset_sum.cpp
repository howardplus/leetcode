/*
 * https://leetcode.com/problems/partition-equal-subset-sum/submissions/
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such that the sum 
 * of elements in both subsets is equal.
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    }
};

int main() {
	Solution s;

	vector<int> t1{1,2,3,4,5,6,7};
	cout << s.canPartition(t1) << endl;

	//vector<int> t2{1,5,11,5};
	vector<int> t2{1,2,3};
	cout << s.canPartition(t2) << endl;

	vector<int> t3{1,2,3,5};
	cout << s.canPartition(t3) << endl;

	return 0;
}
