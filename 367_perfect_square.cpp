/*
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long sum = 0, i = 1; sum < num; i += 2) {
            sum += i;
            if (sum == num) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPerfectSquare(1) << endl;
    cout << s.isPerfectSquare(4) << endl;
    cout << s.isPerfectSquare(15) << endl;
    cout << s.isPerfectSquare(2147483647) << endl;

    return 0;
}
