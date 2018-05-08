/*
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int alphabets[26] = {0};
        for (auto c : s) {
            alphabets[c-'a']++;     
        }
        for (auto c: t) {
            alphabets[c-'a']--;
        }
        for (auto a: alphabets) {
            if (a != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isAnagram("", "") << endl;
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;

    return 0;
}
