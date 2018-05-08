/*
 * https://leetcode.com/problems/majority-element/description/
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        map<int, int> m;
        for (auto n: nums) {
            if (m.find(n) == end(m))
                m[n] = 0;
            else
                m[n]++;
        }

        int maxE = -1;
        int e = -1;
        for (auto i: m) {
            if (i.second > maxE) {
                maxE = max(maxE, i.second);
                e = i.first;
            }
        }

        return e;
    }
};

int main()
{
    Solution s;
    auto v1 = vector<int>{1,3,0,2,3,9,3,3};
    cout << s.majorityElement(v1) << endl;
    auto v2 = vector<int>{1};
    cout << s.majorityElement(v2) << endl;
    return 0;
}
