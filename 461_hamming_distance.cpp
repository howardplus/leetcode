/*
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;       
        int dist = 0;
        while (z) {
            z = z & z-1;
            dist++;
        }
        return dist;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
    cout << s.hammingDistance(1, 1) << endl;
    return 0;
}
