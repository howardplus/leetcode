/*
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 */
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        const char *cstr = s.c_str();
        for (auto i=1; i<len/2+1; i++) {
            if (memcmp(&cstr[0], &cstr[i], i) == 0) {
                if (len % i != 0)
                    continue;
                // match until end of string
                bool match = true;
                int j = i * 2;
                while (j < len) {
                    if (memcmp(&cstr[0], &cstr[j], i) != 0) {
                        match = false;
                        break;
                    }
                    j += i;
                }

                if (!match)
                    continue;

                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("aba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;

    return 0;
}
