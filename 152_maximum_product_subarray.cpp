/*
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int max_so_far = nums[0];
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];

        for (auto i=1; i<nums.size(); i++) {
            auto n = nums[i];

            if (n < 0) {
                int temp = max_ending_here;
                max_ending_here = max(n, min_ending_here * n);
                min_ending_here = min(n, temp * n);
            } else {
                max_ending_here = max(n, max_ending_here * n);
                min_ending_here = min(n, min_ending_here * n);
            }

            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};

int main()
{
    Solution s;

    auto t1 = vector<int>{2,3,-2,4};
    cout << s.maxProduct(t1) << endl;

    auto t2 = vector<int>{-2,3,-4};
    cout << s.maxProduct(t2) << endl;

    auto t3 = vector<int>{2,3,-1,6};
    cout << s.maxProduct(t3) << endl;

    auto t4 = vector<int>{-1,-2,-9,-6};
    cout << s.maxProduct(t4) << endl;

    auto t5 = vector<int>{0, 2};
    cout << s.maxProduct(t5) << endl;

    auto t6 = vector<int>{7, -2, -4};
    cout << s.maxProduct(t6) << endl;

    auto t7 = vector<int>{3, -1, 4};
    cout << s.maxProduct(t7) << endl;

    auto t8 = vector<int>{2, -5, -2, -4, 3};
    cout << s.maxProduct(t8) << endl;

    auto t9 = vector<int>{2, 3, -1, 1, -3, 3, 0};
    cout << s.maxProduct(t9) << endl;

    return 0;
}
