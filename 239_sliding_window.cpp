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
#include <queue>

using namespace std;

class Solution { 
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> result;
        deque<int> d;

        for (auto i=0; i<nums.size(); i++) {
            if (!d.empty() && d.front() <= i-k)
                d.pop_front();

            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();

            d.push_back(i);

            if (i >= k-1)
                result.push_back(nums[d.front()]);
        }

        return result;
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

    auto t3 = s.maxSlidingWindow(vector<int>{1,-1}, 1);
    for (auto i: t3)
        cout << i << endl;
    cout << endl;

    return 0;
}
