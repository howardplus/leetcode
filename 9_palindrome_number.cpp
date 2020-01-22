/*
 * https://leetcode.com/problems/palindrome-number/
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    
        if (x < 0)
            return false;
        else if (x < 10)
            return true;

        stack<int> s{};
        queue<int> q{};
        while (x > 0) {
            auto d = int{x % 10};
            x = x / 10;
            s.push(d);
            q.push(d);
        }

        while (!s.empty()) {
            if (s.top() != q.front())
                return false;

            s.pop();
            q.pop();
        }
        return true;
    }
};

int main() {
    Solution s;

    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(1221) << endl;
    cout << s.isPalindrome(10) << endl;

    return 0;
}
