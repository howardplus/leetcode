/*
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.size() == 0)
            return 0;

        vector<int> v(height.size(), 0);

        int top = 0;
        for (auto i=0; i<height.size(); i++) {
            top = max(height[i], top);
            v[i] = top;
        }

        int top2 = 0;
        int j = height.size()-1;
        while (height[j] < top) {
            top2 = max(height[j], top2);
            v[j--] = top2;
        }

        int vol = 0;
        for (auto i=0; i<height.size(); i++) {
            vol += (v[i] - height[i]);
        }
        return vol;
    }
};

int main()
{
    Solution s;

    vector<int> t1{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(t1) << endl;

    return 0;
}
