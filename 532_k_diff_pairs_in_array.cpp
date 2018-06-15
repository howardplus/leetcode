/*
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * Given an array of integers and an integer k, you need to find the number of
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an
 * integer pair (i, j), where i and j are both numbers in the array and their
 * absolute difference is k.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, bool> m;

        if (nums.size() == 0)
            return 0;

        sort(begin(nums), end(nums));

        for (auto i=0; i<nums.size()-1; i++) {
            if (m.find(nums[i]) != end(m))
                continue;
            else 
                m[nums[i]] = true;

            // find the target
            int target = nums[i] + k;
            if (find(begin(nums)+i+1, end(nums), target) != end(nums)) {
                count++; 
            }
        }

        return count; 
    }
};

int main() {
    Solution s;

/*
    vector<int> t1 = {3,1,4,1,5};
    cout << s.findPairs(t1, 2) << endl;
*/
    
    vector<int> t2 = {3,1,4,1,5};
    cout << s.findPairs(t2, 0) << endl;
    
    return 0;
}
