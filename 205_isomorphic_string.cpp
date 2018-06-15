/*
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() <= 1)
            return true;
            
        unordered_map<char, char> m1, m2;
        for (auto i=0; i<s.length(); i++) {
            auto s1 = s[i];
            auto t1 = t[i];

            if (m1.find(s1) == end(m1)) {
                if (m2.find(t1) != end(m2))
                    return false;
                m1[s1] = t1;
                m2[t1] = s1;
            } else if (m1[s1] != t1) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("ab", "ba") << endl;
    cout << s.isIsomorphic("ab", "aa") << endl;

    return 0;
}
