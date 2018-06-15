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
        if (matrix.size() <= 1 || matrix[0].size() <= 1)
            return true;

        for (auto i=1; i<matrix.size(); i++) {
            for (auto j=1; j<matrix[0].size(); j++) {
                if (matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
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
