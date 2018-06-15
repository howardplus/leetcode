/*
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 *
 * Find the letter that was added in t.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (auto c : t) {
            if (m.find(c) == end(m))
                m[c] = 1;
            else
                m[c]++;
        } 

        for (auto c : s) {
            if (m.find(c) == end(m))
                return c;
            else if (m[c] == 1)
                m.erase(c);
            else
                m[c]--; 
        }

        // last one is the diff
        return begin(m)->first;
    }
};

int main()
{
    Solution s;

    cout << s.findTheDifference("abcde", "edcbaf") << endl;
    cout << s.findTheDifference("aaa", "aaaa") << endl;

    return 0;
}