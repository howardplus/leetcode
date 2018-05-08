/*
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 * For example, these are arithmetic sequence:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic.
 *
 * 1, 1, 2, 5, 7
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 *
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means
 * that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the array A.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;

        auto count = 0;
        for (auto i=0; i<A.size()-2; i++) {
            int step = A[i+1] - A[i]; 
            for (auto j=i+2; j<A.size(); j++) {
                if ((A[j] - A[j-1]) == step) 
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;

    vector<int> v1{};
    cout << s.numberOfArithmeticSlices(v1) << endl;

    vector<int> v2{1};
    cout << s.numberOfArithmeticSlices(v2) << endl;

    vector<int> v3{1,2};
    cout << s.numberOfArithmeticSlices(v3) << endl;

    vector<int> v4{1,2,3,4};
    cout << s.numberOfArithmeticSlices(v4) << endl;
    return 0;
}
