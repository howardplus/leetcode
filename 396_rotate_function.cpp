/*
 * https://leetcode.com/problems/rotate-function/description/
 *
 * Given an array of integers A and let n to be its length.
 *
 * Assume Bk to be an array obtained by rotating the array A k positions
 * clock-wise, we define a "rotation function" F on A as follow:
 *
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
 *
 * Calculate the maximum value of F(0), F(1), ..., F(n-1).
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(const vector<int>& A) {
        if (A.size() == 0)
            return 0;

        int s = 0;        
        for (auto n : A)
            s += n;

        int f = 0;
        for (auto i=0; i<A.size(); i++) {
            f += (i*A[i]);
        }

        int m = f;
        for (auto i=0; i<A.size()-1; i++) {
            auto diff = s - A.size() * A[i];
            int f1 = f - diff;
            m = max(m, f1);
            f = f1;
        }

        return m;
    }
};

int main()
{
    Solution s;
    cout << s.maxRotateFunction({}) << endl;
    cout << s.maxRotateFunction({4,3,2,6}) << endl;
    return 0;
}
