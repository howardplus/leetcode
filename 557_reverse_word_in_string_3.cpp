/*
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j <= s.size()) {
            if (s[j] == ' ' || j == s.size()) {
                // reverse between i and j-1
                for (int k=i; k<i+(j-i)/2; k++) {
                    swap(s[k], s[j+i-1-k]);
                }
                i = j+1;
            }
            j++; 
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
