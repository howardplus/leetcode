/*
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * Given two arrays, write a function to compute their intersection.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m1, m2;
        for (auto n : nums1) {
            if (m1.find(n) == end(m1))
                m1[n] = true;
        }
        for (auto n : nums2) {
            if (m2.find(n) == end(m2))
                m2[n] = true;
        }

        vector<int> result;
        for (auto m : m1) {
            if (m2.find(m.first) != end(m2))
                result.push_back(m.first);
        }

        return result;
    }
};

int main()
{
    auto v1 = vector<int>{1,2,2,1,3};
    auto v2 = vector<int>{2,2,3};

    Solution s;
    auto r1 = s.intersection(v1, v2);

    for (auto i : r1) {
        cout << i << endl;
    }
    
    return 0;
}
