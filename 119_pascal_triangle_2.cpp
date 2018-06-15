/*
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev; 
        
        // idx = 0;
        prev.push_back(1);
        if (rowIndex == 0)
            return prev;

        // grow the triangle
        for (auto idx = 1; idx <= rowIndex; idx++) {
            auto row = vector<int>(idx+1);
            row[0] = row[idx] = 1;    
            for (auto j=1; j<idx; j++) {
                row[j] = prev[j] + prev[j-1];
            }

            if (idx == rowIndex) {
                return row;
            }
            prev = row;
        }

        // not reached
        return prev;
    }
};

int main()
{
    Solution s;    
    auto v = s.getRow(3);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
