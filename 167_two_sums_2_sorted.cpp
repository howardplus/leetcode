/*
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bsearch(vector<int>& numbers, int val, int start) {
        int i = start;
        int j = numbers.size() -1;
        while (i <= j) {
            int mid = i + (j-i)/2;  
            if (numbers[mid] == val)
                return mid;
            else if (numbers[mid] < val)
                i = mid+1;
            else
                j = mid-1;
        }
        return 0;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        // binary search on the array to the right of this number
        for (auto i=0; i<numbers.size()-1; i++) {
            int val = target - numbers[i];
            int j = bsearch(numbers, val, i+1);
            if (j != 0) {
                return vector<int>{i+1, j+1};
            }
        }
        return vector<int>{};
    }
};

int main()
{
    Solution s;

    auto v1 = vector<int>{3,24,50,79,88,150,345};
    auto r1 = s.twoSum(v1, 200);
    for (auto i : r1)
        cout << i << " ";
    cout << endl;

    return 0;
}
