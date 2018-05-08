/*
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> v{};

        if (nums.size() == 0 || nums.size() < k)
            return v;

        int max_so_far = nums[0];
        int max_index = 0;
        for (auto i=0; i<nums.size(); i++) {
            if (max_index < (i-k+1)) {
                max_so_far = nums[i-k+1]; 
                max_index = i-k+1;
                for (auto j=i-k+2; j<=i; j++) {
                    if (nums[j] > max_so_far) {
                        max_index = j;
                        max_so_far = nums[j];
                    } 
                }
            } else {
                if (nums[i] > max_so_far) {
                    max_index = i;
                    max_so_far = nums[i];
                }
            }

            if (i >= (k-1))
                v.push_back(max_so_far); 
        }
        return v;
    }
};

int main()
{
    Solution s;

    auto t0 = s.maxSlidingWindow(vector<int>{}, 0);
    for (auto i: t0)
        cout << i << endl;
    cout << endl;

    auto t1 = s.maxSlidingWindow(vector<int>{1,3,-1,-3,5,3,6,7}, 3);
    for (auto i: t1)
        cout << i << endl;
    cout << endl;

    auto t2 = s.maxSlidingWindow(vector<int>{1,3,-1,5,2,3,4,7}, 3);
    for (auto i: t2)
        cout << i << endl;
    cout << endl;

    auto t3 = s.maxSlidingWindow(vector<int>{1,3,2}, 3);
    for (auto i: t3)
        cout << i << endl;
    cout << endl;

    return 0;
}
