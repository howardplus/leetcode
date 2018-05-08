/*
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000
 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.length() == 0)
            return 0;
        else if (s.length() == 1)
            return 1;

        // 2 or above
        char l = s[0];
        char r = s[s.length()-1];
        if (l == r) {
            return 2 + longestPalindromeSubseq(s.substr(1, s.length()-2));
        } else {
            return max(longestPalindromeSubseq(s.substr(0, s.length()-1)),
                       longestPalindromeSubseq(s.substr(1, s.length()-1)));
        }
    }
};

int main()
{
    Solution s;

    cout << s.longestPalindromeSubseq("bbbab") << endl;
    cout << s.longestPalindromeSubseq("agbdba") << endl;
    cout << s.longestPalindromeSubseq("cbbd") << endl;
    cout << s.longestPalindromeSubseq("abcdefedcba") << endl;
    cout << s.longestPalindromeSubseq("axbxcxdxexfzezdzcba") << endl;

    return 0;
}
