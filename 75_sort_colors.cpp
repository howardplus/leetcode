/*
 * https://leetcode.com/problems/sort-colors/description/
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int i, int j, vector<int>& v1, vector<int>& v2) {
        int v1i = 0, v2i = 0;
        int idx;
        for (idx = i; idx <= j; idx++) {
            int val1 = (v1i < v1.size() ? v1[v1i] : INT32_MAX);
            int val2 = (v2i < v2.size() ? v2[v2i] : INT32_MAX);

            if (val1 < val2) {
                nums[idx] = val1;
                v1i++;
            } else {
                nums[idx] = val2;
                v2i++;
            }
        }
    }

    void sort(vector<int>& nums, int i, int j) {
        if (i >= j)
            return;

        int mid = i + (j-i)/2;
        sort(nums, i, mid);
        sort(nums, mid+1, j);
        
        // a copy here
        vector<int> x(begin(nums)+i, begin(nums)+mid+1);
        vector<int> y(begin(nums)+mid+1, begin(nums)+j+1);

        merge(nums, i, j, x, y);
    }

    void sortColors(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
    }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{2,0,2,1,1,0};

    s.sortColors(t1);

    for (auto i : t1)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
