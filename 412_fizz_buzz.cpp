/*
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i=1; i<=n; i++) {
            if (i % 15 == 0)
                v.push_back("FizzBuzz");
            else if (i % 3 == 0)
                v.push_back("Fizz"); 
            else if (i % 5 == 0)
                v.push_back("Buzz"); 
            else
                v.push_back(to_string(i));
        }
        return v;
    }
};

int main() {
    Solution s;
    auto t1 = s.fizzBuzz(15);
    for (auto s : t1)
        cout << s << endl;

    return 0;
}
