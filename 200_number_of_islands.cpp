/*
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findWater(int r, int c, const vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if (r >= grid.size() || c >= grid[0].size() || visited[r][c])
            return;

        visited[r][c] = true;
        if (grid[r][c] == 0)
            return;

        findWater(r+1, c, grid, visited);
        findWater(r, c+1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        auto m = grid.size();
        auto n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int num = 0;
        for (auto r=0; r<grid.size(); r++) {
            for (auto c=0; c<grid[0].size(); c++) {
                if (!visited[r][c]) {
                    if (grid[r][c] == 1) {
                        findWater(r, c, grid, visited);
                        num++;
                    } else
                        visited[r][c] = true;
                }
            }
        }
        return num;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> t1;
    t1.push_back({1,1,0,1,0});
    t1.push_back({1,1,0,1,0});
    t1.push_back({1,1,0,0,1});
    t1.push_back({0,0,1,0,1});

    cout << s.numIslands(t1) << endl;    

    return 0;
}
