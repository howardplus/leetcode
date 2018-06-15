/*
 * https://leetcode.com/problems/power-of-two/description/
 *
 * Given an integer, write a function to determine if it is a power of two.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & n-1) == 0);
    }
};

int main() {
    return 0;
}
