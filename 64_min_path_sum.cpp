#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSumFn(vector<vector<int>>& grid, vector<vector<int>>& val, int m, int n) {

        if (m == grid.size()-1 &&
            n == grid[0].size()-1) {
            val[m][n] = grid[m][n];
            return val[m][n];
        }

        if (m == grid.size()-1) {
            val[m][n] = grid[m][n] + minPathSumFn(grid, val, m, n+1);
        } else if (n == grid[0].size()-1) {
            val[m][n] = grid[m][n] + minPathSumFn(grid, val, m+1, n);
        } else {
            int right = 0, down = 0;
            if (val[m][n+1]) {
                right = val[m][n+1];
            }
            if (val[m+1][n]) {
                down = val[m+1][n];
            }

            if (right == 0)
                right = minPathSumFn(grid, val, m, n+1);
            if (down == 0)
                down = minPathSumFn(grid, val, m+1, n);

            if (right < down)
                val[m][n] = grid[m][n] + right;
            else
                val[m][n] = grid[m][n] + down;
        }

        return val[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> val(grid.size(), vector<int>(grid[0].size(), 0));
        return minPathSumFn(grid, val, 0, 0);
    }
};

int main() {
	Solution s;

	vector<vector<int>> t1 = {
        {1,1,1},
        {9,7,2},
        {8,1,1}
	};

	cout << s.minPathSum(t1) << endl;

    vector<vector<int>> t2 = 
    {{1,4,8,6,2,2,1,7},{4,7,3,1,4,5,5,1},{8,8,2,1,1,8,0,1},{8,9,2,9,8,0,8,9},{5,7,5,7,1,8,5,5},{7,0,9,4,5,6,5,6},{4,9,9,7,9,1,9,0}};

	cout << s.minPathSum(t2) << endl;
	return 0;
}
