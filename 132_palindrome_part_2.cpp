/*
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s)
    {
        auto i = 0;
        auto j = s.length() - 1;

        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    bool tryCut(const string &s, int i)
    {
        cout << "try " << s << " with " << i << endl;
        if (i == 0) {
            return isPalindrome(s);
        }

        // at least 1 cut, do it recursively
        for (auto idx=1; idx < s.length(); idx++) {
            if (isPalindrome(s.substr(0, idx)) &&
                tryCut(s.substr(idx, s.length()-idx), i-1))
                return true;
        }

        return false;
    }

    int minCut(string s)
    {
        // take care of special cases
        auto l = s.length();
        if (l == 0 || l == 1 || isPalindrome(s)) {
            return 0;
        } else if (l == 2) {
            return 1;
        }

        // now l is > 2, find the cuts
        for (auto i=1; i<l-1; i++) {
            cout << "==> cut = " << i << endl;
            if (tryCut(s, i))
                return i;
        }

        return l-1;
    }
};

int main()
{
    Solution s;

#if 0
    cout << "aab: " << s.minCut("aab") << endl;
    cout << ": " << s.minCut("") << endl;
    cout << "a: " << s.minCut("a") << endl;
    cout << "aba: " << s.minCut("aba") << endl;
    cout << "aabbc: " << s.minCut("aabbc") << endl;
    cout << "leet: " << s.minCut("leet") << endl;
#endif
    cout << "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi" << s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;

    return 0;
}
