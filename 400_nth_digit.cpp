/*
 * https://leetcode.com/problems/nth-digit/description/
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int i = 0;
        int prev = 0;
        int limit = 9;
        while (n > limit) {
            i++;
            prev = limit;
            limit += (9 * (i*10) * (i+1)); 
        }

        // got the partition number
        auto m = (n - prev - 1)/(i+1) + 1 + prev;

        // which digit?
        auto d = n % (i+1);
    
        auto digit = 1;
        for (auto j=0; j<d; j++) {
            digit = digit * 10; 
        }
        cout << digit << endl;

        return (m / digit) % 10;
    }
};

int main()
{
    Solution s;

    //cout << s.findNthDigit(3) << endl;
    //cout << s.findNthDigit(12) << endl;
    cout << s.findNthDigit(100000000) << endl;
    //cout << s.findNthDigit(14) << endl;

    return 0;
}
