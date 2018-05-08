/*
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool first_row = false, first_col = false;

        for (auto e : matrix ) {
            if (e[0] == 0) {
                first_col = true;
                break;
            }
        }

        for (auto e : matrix[0]) {
            if (e == 0) {
                first_row = true;
                break;
            }
        }

        for (auto i = 1; i < matrix.size(); i++) {
            for (auto j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // use first row and col to set zeroes
        for (auto i = 1; i<matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                cout << "set row " << i << endl;
                for (auto c=1; c<matrix[0].size(); c++) {
                    matrix[i][c] = 0;
                }
            }
        }

        for (auto j = 1; j<matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                cout << "set col " << j << endl;
                for (auto r=1; r<matrix.size(); r++) {
                    matrix[r][j] = 0;
                }
            }
        }

        // finally, get first row and col
        if (first_row) {
            for (auto c=0; c<matrix[0].size(); c++) {
                matrix[0][c] = 0;
            }
        }

        if (first_col) {
            for (auto r=0; r<matrix.size(); r++) {
                matrix[r][0] = 0;
            }
        }
    }

    void print(const vector<vector<int>>& matrix)
    {
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "==========" << endl;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    vector<vector<int>> t1 = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    
    s.print(t1);
    s.setZeroes(t1);
    s.print(t1);

    vector<vector<int>> t2 = {{1,2,6,7,0},{8,6,8,6,0},{1,2,9,6,3}};

    s.print(t2);
    s.setZeroes(t2);
    s.print(t2);
    return 0;
}
