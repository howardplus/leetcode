/*
 * https://leetcode.com/problemset/all/?search=266
 *
 * Given a string, determine if a permutation of the string could form a
 * palindrome.
 *
 * Examples:
 * "code" -> false
 * "aab" -> true
 * "carerac" -> true
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool hasPalindromePermutation(string str) {
        map<char, int> m;
        for (auto c : str) {
            if (m.find(c) == end(m))
                m[c] = 1;
            else
                m[c]++;
        }

        int odd_count = (str.length() % 2 == 0 ? 0 : 1);
        for (auto kv : m) {
            if (kv.second % 2) {
                if (odd_count-- == 0)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    cout << s.hasPalindromePermutation("code") << endl;
    cout << s.hasPalindromePermutation("aab") << endl;
    cout << s.hasPalindromePermutation("carerac") << endl;

    return 0;
}
