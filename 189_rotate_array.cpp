/*
 * https://leetcode.com/problems/rotate-array/description/
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> copy = nums;
        int n = nums.size();
        for (auto i=0; i<n; i++) {
            nums[(i+k)%n] = copy[i];
        }
    }
};

int main()
{
    Solution s;

    vector<int> t1{1,2,3,4,5,6,7};
    s.rotate(t1, 3);

    for (auto i: t1) {
        cout << i << endl;
    }

    return 0;
}
