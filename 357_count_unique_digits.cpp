/*
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10^n.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        else {
            int perm = 9;
            for (auto i=0; i<n-1; i++) {
                perm = perm * (9-i);
            }
            return perm + countNumbersWithUniqueDigits(n-1);
        }
    }
};

int main()
{
    Solution s;
    cout << s.countNumbersWithUniqueDigits(0) << endl;
    cout << s.countNumbersWithUniqueDigits(1) << endl;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    cout << s.countNumbersWithUniqueDigits(3) << endl;
    return 0;
}
