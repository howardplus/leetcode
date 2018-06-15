/*
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int perimeter(vector<vector<int>>& grid, int r, int c) {
        int adj = 0;
        if (r != 0 && grid[r-1][c] == 1)
            adj++;
        if (r != grid.size()-1 && grid[r+1][c] == 1)
            adj++;
        if (c != 0 && grid[r][c-1] == 1)
            adj++;
        if (c != grid[0].size()-1 && grid[r][c+1] == 1)
            adj++;
        return 4 - adj;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        for (auto r=0; r<grid.size(); r++) { 
            for (auto c=0; c<grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    p += perimeter(grid, r, c);
                }
            }
        }
        return p;
    }
};

int main() {
    Solution s;

    vector<vector<int>> t1 = {
                {0,1,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {1,1,0,0}};

    cout << s.islandPerimeter(t1) << endl;

    return 0;
}
