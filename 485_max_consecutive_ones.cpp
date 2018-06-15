/*
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_running = 0;
        int max_so_far = 0;
        for (auto n : nums) {
            if (n == 0) {
                max_so_far = max(max_so_far, max_running);
                max_running = 0;
            } else {
                max_running++;
            }
        }
        return max(max_so_far, max_running);
    }
};

int main() {
    Solution s;

    vector<int> t1 = {1,1,0,1,1,1};

    cout << s.findMaxConsecutiveOnes(t1) << endl;

    return 0;
}
