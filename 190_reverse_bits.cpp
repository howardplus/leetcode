/*
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 */
#include <stdint.h>
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        for (int i=0; i<16; i++) {
            uint32_t mask_a = 0x80000000 >> i;
            uint32_t mask_b = 0x00000001 << i;
            uint32_t a = n & mask_a;
            uint32_t b = n & mask_b;
            if (!!a != !!b) {
                if (a) {
                    n &= ~mask_a;
                    n |= mask_b;
                } else {
                    n &= ~mask_b;
                    n |= mask_a;
                }
            }
        }
        return n;
    }
};

int main()
{
    Solution s;
    uint32_t t1 = 43261596;
    cout << t1 << " => " << s.reverseBits(t1) << endl;
}
