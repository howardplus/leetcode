/*
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 *
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 */
#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    bool isToeplitzMatrix(const vector<vector<int>>& matrix) {
        // single row or column always return true
        if (matrix.size() == 1 || matrix[0].size() == 1)
            return true;

        // > 2 rows && 2 cols, go through and check upper-left
        for (auto r=1; r<matrix.size(); r++) {
            for (auto c=1; c<matrix[0].size(); c++) {
                if (matrix[r][c] != matrix[r-1][c-1])
                    return false;
            }
        }

        // no mismatch, it's good
        return true;
    }
};

int main()
{
    Solution s;

    auto m1 = vector<vector<int>>{
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}};

    cout << s.isToeplitzMatrix(m1) << endl;

    auto m2 = vector<vector<int>>{
        {3},
        {4},
        {5}};

    cout << s.isToeplitzMatrix(m2) << endl;

    return 0;
}
