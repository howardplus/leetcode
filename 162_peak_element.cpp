/*
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return
 * its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function
 * should return the index number 2.
 */
#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int>& nums)
    {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] < nums[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    Solution s;

    cout << s.findPeakElement(vector<int>{1,2,3,1}) << endl;
    cout << s.findPeakElement(vector<int>{1,2,3,4,5,1}) << endl;
    cout << s.findPeakElement(vector<int>{1,2,3,4,5}) << endl;
    cout << s.findPeakElement(vector<int>{3,2,1}) << endl;
    cout << s.findPeakElement(vector<int>{1,2}) << endl;
    cout << s.findPeakElement(vector<int>{1}) << endl;
    cout << s.findPeakElement(vector<int>{-2147483647,-2147483648}) << endl;
    cout << s.findPeakElement(vector<int>{-2147483648,-2147483647}) << endl;

    return 0;
}
