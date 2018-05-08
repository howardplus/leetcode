/*
 * https://leetcode.com/problems/single-number/description/
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        unordered_map<int, int> m; 

        for (auto n:nums) {
            if (m.find(n) == end(m)) {
                m[n] = 1;
            } else {
                m.erase(n);
            }
        }

        return (*begin(m)).first;
    }
};

int main()
{
    Solution s;

    cout << s.singleNumber({3,0,3,2,0,1,1}) << endl;

    return 0; 
}
