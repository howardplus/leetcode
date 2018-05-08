/*
 * https://leetcode.com/problems/01-matrix/description/
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    pair<bool, pair<int, int>> expand(vector<vector<int>>& m, pair<int, int>& rc, int dir) {
        int r = rc.first;
        int c = rc.second;
        if (dir == 0) {
            r--;
        } else if (dir == 1) {
            r++;
        } else if (dir == 2) {
            c--;
        } else {
            c++;
        }

        // check boundary
        if (r >= 0 && c >= 0 && r < m.size() && c < m[0].size()) {
            if (m[r][c] > m[rc.first][rc.second] + 1) {
                m[r][c] = m[rc.first][rc.second] + 1;
                return make_pair(true, make_pair(r, c));
            } 
        }
        return make_pair(false, pair<int,int>{});
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> dist(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<pair<int, int>> q;        
        for (auto r = 0; r<matrix.size(); r++) {
            for (auto c = 0; c<matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    dist[r][c] = 0;
                    q.push(make_pair(r, c));
                }
            }
        }

        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                auto result = expand(dist, e, i);
                if (result.first) {
                    q.push(result.second);
                }
            } 
        }
        return dist; 
    }

    void display(vector<vector<int>>& m) {
        for (auto row: m) {
            for (auto col: row) {
                cout << col << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
/*
    vector<vector<int>> t1{{0,0,0},{0,1,0},{0,0,0}};
    auto r1 = s.updateMatrix(t1); 
    s.display(r1);
    vector<vector<int>> t2{{0,0,0},{0,1,0},{1,1,1}};
    auto r2 = s.updateMatrix(t2); 
    s.display(r2);
*/
    vector<vector<int>> t3{{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
    auto r3 = s.updateMatrix(t3); 
    s.display(r3);
    return 0;
}
