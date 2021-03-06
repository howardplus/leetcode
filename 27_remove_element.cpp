/*
 * https://leetcode.com/problems/remove-element/description/
 *
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int j = nums.size()-1;
            while (j>= 0 && nums[j] == val)
                j--;

            int i = 0;
            while (i <= j) {
                if (nums[i] == val) {
                    swap(nums[i], nums[j--]);
                    while (j >= i && nums[j] == val)
                        j--;
                }

                i++;
            }

            return j+1;
        }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{1,2,2,3,4,2};
    auto n1 = s.removeElement(t1, 2);
    for (auto i=0; i<n1; i++)
        cout << t1[i] << " ";
    cout << endl;

    auto t2 = vector<int>{3};
    auto n2 = s.removeElement(t2, 3);
    for (auto i=0; i<n2; i++)
        cout << t2[i] << " ";
    cout << endl;

    auto t3 = vector<int>{0,4,4,0,4,4,4,0,2};
    auto n3 = s.removeElement(t3, 4);
    for (auto i=0; i<n3; i++)
        cout << t3[i] << " ";
    cout << endl;

    auto t4 = vector<int>{2,2,3};
    auto n4 = s.removeElement(t4, 2);
    for (auto i=0; i<n4; i++)
        cout << t4[i] << " ";
    cout << endl;

    return 0;
}
