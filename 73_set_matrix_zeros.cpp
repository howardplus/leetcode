/*
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. With a row vector, set the vector value to true
 *    if there is a 0 anywhere in that row.
 * 2. Do the same with a col vector.
 * 3. Then set row/col to 0 if row/col vector has value true.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        auto rows = vector<bool>(matrix.size(), false);
        auto cols = vector<bool>(matrix[0].size(), false);

        for (auto r=0; r<matrix.size(); r++) {
            for (auto c=0; c<matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    rows[r] = true;
                    cols[c] = true;
                }
            }
        }

        for (auto r=0; r<rows.size(); r++) {
            if (rows[r]) {
                for (auto c=0; c<matrix[0].size(); c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        for (auto c=0; c<cols.size(); c++) {
            if (cols[c]) {
                for (auto r=0; r<matrix.size(); r++) {
                    matrix[r][c] = 0;
                }
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
