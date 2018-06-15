/*
 * https://leetcode.com/problems/plus-one/description/
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        int carry = 0;
        digits[sz-1] += 1;
        for (auto i=sz-1; i>=0; i--) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry)
            digits.insert(begin(digits), 1);

        return digits;
    }
};

int main() {
    Solution s;

    vector<int> t1 = {9,9,9};
    auto r1 = s.plusOne(t1);
    for (auto i : r1)
        cout << i;
    cout << endl;

    vector<int> t2 = {4,3,9,1};
    auto r2 = s.plusOne(t2);
    for (auto i : r2)
        cout << i;
    cout << endl;

    vector<int> t3 = {0};
    auto r3 = s.plusOne(t3);
    for (auto i : r3)
        cout << i;
    cout << endl;


    return 0;
}
