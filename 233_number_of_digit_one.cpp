/*
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12,
 * 13.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0)
            return 0;

        int m = n;
        int count = 0;
        int divisor = 1;

        while (n) {
            int r = n % divisor;
            n /= 10;

            if (r == 0) {
                count += n * divisor;
            } else if (r > 1) {
                count += (n + 1) * divisor;
            } else {
                count += m - n * 9 * divisor - divisor + 1;
            }

            divisor *= 10;
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countDigitOne(13) << endl;
    cout << s.countDigitOne(23) << endl;
    return 0;
}
