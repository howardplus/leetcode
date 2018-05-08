/*
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        if (m == n)
            return m;

        unsigned mask = 0x80000000;
        int result = 0;
        while (mask) {
            if ((mask & m) == 0 && (mask & n) == 0) {
                mask >>= 1;
            } else if ((mask & m) == 0 || (mask & n) == 0) {
                break;
            } else {
                result |= mask & m;
                mask >>= 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    cout << s.rangeBitwiseAnd(5, 5) << endl;
    cout << s.rangeBitwiseAnd(10, 11) << endl;
    return 0;
}
