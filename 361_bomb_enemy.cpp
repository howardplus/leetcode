/*
 * Given a 2D grid, each cell is either a wall 'w', an enemy 'E' or empty '0'.
 * Return the maximum enemies you can kill using one bomb.
 *
 * The bomb kills all the enemies in the same row and col from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 *
 * You can only put the bomb at an empy cell '0'.
 *
 * Example:
 *
 * 0 E 0 0
 * E 0 W E
 * 0 E 0 0
 *
 * return 3 with bomb at (1,1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mark(vector<vector<char>>& grid, vector<vector<int>>& gridCount, int r, int c) {
        int localMax = 0;

        // move up
        for (int i=r-1; i>=0; i--) {
            if (grid[i][c] == '0') {
                gridCount[i][c]++;
                localMax = max(localMax, gridCount[i][c]);
            } else if (grid[i][c] == 'W')
                break;
        }

        // move down
        for (int i=r+1; i<grid.size(); i++) {
            if (grid[i][c] == '0') {
                gridCount[i][c]++;
                localMax = max(localMax, gridCount[i][c]);
            } else if (grid[i][c] == 'W')
                break;
        }

        // move left
        for (int i=c-1; i>=0; i--) {
            if (grid[r][i] == '0') {
                gridCount[r][i]++;
                localMax = max(localMax, gridCount[r][i]);
            } else if (grid[r][i] == 'W')
                break;
        }

        // move right
        for (int i=c+1; i<grid[0].size(); i++) {
            if (grid[r][i] == '0') {
                gridCount[r][i]++;
                localMax = max(localMax, gridCount[r][i]);
            } else if (grid[r][i] == 'W')
                break;
        }

        return localMax;
    }

    int bombEnemies(vector<vector<char>>& grid) {
        int maxVal = 0;
        vector<vector<int>> gridCount(grid.size(), vector<int>(grid[0].size(), 0));
        for (auto r = 0; r < grid.size(); r++) {
            for (auto c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 'E') {
                    int localMax = mark(grid, gridCount, r, c);
                    maxVal = max(maxVal, localMax);
                }
            }
        }
        return maxVal;
    }
};

int main() {
    Solution s;

    auto t1 = vector<vector<char>> {
        {'0', 'E', '0', '0'},
        {'E', '0', 'W', 'E'},
        {'0', 'E', '0', '0'}};

    cout << s.bombEnemies(t1) << endl;

    return 0;
}
