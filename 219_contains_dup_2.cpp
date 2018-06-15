/*
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_map<int, bool> m;

        for (int i=0; i<nums.size(); i++) {
            if ((i-k-1) >= 0) {
                m.erase(nums[i-k-1]);
            }

            auto n = nums[i];
            if (m.find(n) == end(m)) {
                m[n] = true;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << s.containsNearbyDuplicate({1,2,3,4,5,3,1}, 4) << endl;    
    cout << s.containsNearbyDuplicate({1,2,3,4,5,6,1}, 4) << endl;    
    cout << s.containsNearbyDuplicate({1,2,3,4,6,6,1}, 2) << endl;    
    cout << s.containsNearbyDuplicate({1,2,3,1}, 3) << endl;    
    return 0;
}
