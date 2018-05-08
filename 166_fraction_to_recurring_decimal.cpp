/*
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 *
 * For example,
 *
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        stringstream ss;
        int i = numerator/denominator;
        ss << i; 

        numerator -= i * denominator;

        if (numerator % denominator) {
            ss << ".";
            vector<int> v;
            while (true) {
                numerator *= 10;
                i = numerator / denominator;
                numerator -= i * denominator;
                v.push_back(i);
/*
                int f = numerator % denominator;
                if (f == 0) {
                    for (auto m: v)
                        ss << m;
                    break;
                } else {
                    // look for dup
                }
*/
            }
        }

        return ss.str();
    }
};

int main()
{
    Solution s;

    cout << s.fractionToDecimal(200, 10) << endl;
    cout << s.fractionToDecimal(111, 2) << endl;
    cout << s.fractionToDecimal(1, 2) << endl;
    cout << s.fractionToDecimal(1, 3) << endl;
    cout << s.fractionToDecimal(1, 7) << endl;
    cout << s.fractionToDecimal(1, 99) << endl;

    return 0;
}
