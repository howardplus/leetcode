/*
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 *
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 */
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Solution {
public:
    void removePrefix0(string& s) {
        for (auto i=0; i<s.length(); i++) {
            if (s[i] == '0')
                continue;
            else {
                s = s.substr(i, s.length()-i);
                return;
            }
        }
        s = "0";
    }

    bool isSmaller(string a, string b) {
        removePrefix0(a);
        removePrefix0(b);

        if (a.length() > b.length()) {
            return false;
        } else if (a.length() < b.length()) {
            return true;
        } else {
            for (auto i=0; i<a.length(); i++) {
                if ((a[i] - '0') < (b[i] - '0'))
                    return true;
                else if ((a[i] - '0') > (b[i] - '0'))
                    return false;
            }
        }
        // same
        return false;
    }

    string removeOneDigit(string s, int k) {
        if (k <= 0) {
            return s;
        }

        string cmp = s.substr(1, s.length()-1);
        for (auto i=1; i<s.length(); i++) {
            string s1 = s.substr(0, i) + s.substr(i+1, s.length()-i-1);
            if (isSmaller(s1, cmp)) {
                cmp = s1;
            }
        }
        removePrefix0(cmp);
        return removeOneDigit(cmp, k-1);
    }

    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0"; 
        
        return removeOneDigit(num, k);
    }
};

int main()
{
    Solution s;
    
    cout << s.removeKdigits("1432219", 3) << endl; // 1219
    cout << s.removeKdigits("10200", 1) << endl; // 200
    cout << s.removeKdigits("10", 2) << endl; // 0
    cout << s.removeKdigits("10", 1) << endl; // 0
    cout << s.removeKdigits("212", 1) << endl; // 0
    cout << s.removeKdigits("100", 1) << endl; // 0

    return 0;
}
