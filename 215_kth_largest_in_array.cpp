/*
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(const vector<int>& nums, int k) {
        vector<int> v = nums; 
        priority_queue<int> pq{begin(v), end(v)};

        while (k-- > 1) {
            pq.pop(); 
        }

        return pq.top();
    }
};

int main()
{
    Solution s;

    cout << s.findKthLargest(vector<int>{3,2,1,5,6,4}, 2) << endl;
    return 0;
}
