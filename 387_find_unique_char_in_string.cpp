/*
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Note: You may assume the string contain only lowercase letters.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m; 
        for (auto c : s) {
            if (m.find(c) == end(m))
                m[c] = 1;
            else
                m[c]++;
        }

        // scan and find first with value of 1
        for (auto i=0; i<s.length(); i++) {
            if (m[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    return 0;
}
