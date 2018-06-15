/*
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        if (numRows == 0)
            return v;

        for (auto i=0; i<numRows; i++) {
            auto row = vector<int>(i+1);
            if (i == 0) {
                row[0] = 1;
            } else {
                row[0] = row[i] = 1;
                for (auto j=1; j<i; j++) {
                    row[j] = v[i-1][j] + v[i-1][j-1];
                }
            }

            v.push_back(row);
        }

        return v;
    }
};

int main()
{
    Solution s;
    auto r1 = s.generate(0);
    auto r2 = s.generate(5);
    for (auto i : r2) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    } 
    return 0;
}
