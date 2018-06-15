/*
 * https://leetcode.com/problems/happy-number/description/
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            int m = n % 10;
            sum += (m * m); 
            n = n/10; 
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, bool> m; 
        while (true) {
            int sum = getSum(n);
            auto r = m.find(sum);
            if (sum == 1)
                return true;
            if (r != end(m))
                return false;
            m[sum] = true;
            n = sum;
        }
        // not reached
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(18) << endl;
    return 0;
}
