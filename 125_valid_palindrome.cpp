/*
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        string s1;
        for (auto it=begin(s); it != end(s); ++it) {
            if (isalnum(*it))
                s1.append(1, tolower(*it));
        }

        int sz = s1.length();
        if (sz == 0)
            return true;

        for (auto i=0; i<sz/2; i++) {
            if (s1[i] != s1[sz-i-1])
                return false;
        }
        
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("") << endl;
    cout << s.isPalindrome("a") << endl;
    cout << s.isPalindrome("ab") << endl;
    cout << s.isPalindrome("aa") << endl;
    cout << s.isPalindrome("aba") << endl;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
