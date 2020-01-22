#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> left(matrix.size(), 0);
        vector<int> top(matrix[0].size(), 0);

        for (auto m=0; m<matrix.size(); m++) {
            for (auto n=0; n<matrix[0].size(); n++) {
                if (matrix[m][n] == 0) {
                    left[m] = 1;
                    top[n] = 1;
                }
            }
        }

        for (auto m=0; m<matrix.size(); m++) {
            for (auto n=0; n<matrix[0].size(); n++) {
                if (left[m] == 1 || top[n] == 1)
                    matrix[m][n] = 0;
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<int>> t1 = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}
    };

    s.setZeroes(t1);

    for (auto m=0; m<t1.size(); m++) {
        for (auto n=0; n<t1[0].size(); n++) {
            cout << t1[m][n] << " ";
        }
        cout << endl;
    }
    return 0;
}
