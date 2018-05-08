/*
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height)
    {
        // take 2 extremes, and one by one move in
        int max_area = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            max_area = max(max_area, (j-i)*min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.maxArea(vector<int>({1,1})) << "," << 1 << endl;
    cout << s.maxArea(vector<int>({1,2})) << "," << 1 << endl;
    cout << s.maxArea(vector<int>({2,1})) << "," << 1 << endl;
    cout << s.maxArea(vector<int>({5,1,3})) << "," << 6 << endl;
    cout << s.maxArea(vector<int>({1,2,1})) << "," << 2 << endl;
    cout << s.maxArea(vector<int>({5,4,3,4,5})) << "," << 20 << endl;
    cout << s.maxArea(vector<int>({1,2,4,3})) << "," << 4 << endl;
    return 0;
}
