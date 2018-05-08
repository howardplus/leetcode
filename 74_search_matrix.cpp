/*
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        // perform binary search on row first
        int low = 0;
        int high = matrix.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                if (mid == matrix.size() - 1 ||
                    matrix[mid+1][0] > target)
                    break;
                else
                    low = mid+1;
            } else {
                if (mid == 0)
                    return false;
                else if (matrix[mid-1][0] < target) {
                    mid = mid - 1;
                    break;
                } else
                    high = mid-1;
            }
        }

        int row = mid;

        // use the row and perform binary search
        low = 0;
        high = matrix[0].size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        return false;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    vector<vector<int>> t1 = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << "t1(10): " << s.searchMatrix(t1, 10) << endl;
    cout << "t1(3): " << s.searchMatrix(t1, 3) << endl;
    cout << "t1(4): " << s.searchMatrix(t1, 4) << endl;
    cout << "t1(16): " << s.searchMatrix(t1, 16) << endl;
    cout << "t1(17): " << s.searchMatrix(t1, 17) << endl;

    vector<vector<int>> t2 = {{1,1},{2,2}};
    cout << "t2(0): " << s.searchMatrix(t2, 0) << endl;

    vector<vector<int>> t3 = {{-9, -7}};
    cout << "t3(-15): " << s.searchMatrix(t3, -15) << endl;

    vector<vector<int>> t4 = {{1}};
    cout << "t4(1): " << s.searchMatrix(t4, 1) << endl;

    vector<vector<int>> t5 = {{}};
    cout << "t5(1): " << s.searchMatrix(t5, 1) << endl;

    return 0;
}
