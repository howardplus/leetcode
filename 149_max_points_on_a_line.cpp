/*
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points)
    {
        int max = 0;

        for (auto i=0; i<points.size(); i++) {
            auto &p = points[i];
            vector<bool> used(points.size(), 0);
            used[i] = true;
            int cur = 1;

            for (auto j=i+1; j<points.size(); j++) {

                if (used[j]) continue;

                // deal with same point
                if (points[j].x == points[i].x &&
                    points[j].y == points[i].y) {
                    cur++;
                    continue;
                }

                cur++;

                // find 3rd point and check if it's on the same line
                for (auto k=j+1; k<points.size(); k++) {
                    if (used[k]) continue;

                    // check colinearity
                    float diff = (float)(points[k].y-points[j].y)*(float)(points[j].x-points[i].x) - (float)(points[j].y-points[i].y)*(float)(points[k].x-points[j].x);

                    cout << "diff = " << diff << endl;
                    if (diff < 0)
                        diff = (-1)*diff;

                    if (diff < 0.00000001) {
                        cur++;
                        used[k] = true;
                        cout << "colinear: " << i << "," << j << "," << k << endl;
                        cout << cur << endl;
                    }
                }

                if (cur > max)
                    max = cur;

                cur = 1;
            }

            if (cur > max)
                max = cur;
        }

        return max;
    }
};

int main()
{
    Solution s;

    /*
    vector<Point> t1 = {Point(1,1), Point(1,3), Point(0,9), Point(2,2), Point(3,3)};
    cout << "t1: " << s.maxPoints(t1) << endl;

    vector<Point> t2 = {Point(0,0)};
    cout << "t2: " << s.maxPoints(t2) << endl;
    */

    vector<Point> t3 = {Point(0,0), Point(1,65536), Point(65536,0)};
    cout << "t3: " << s.maxPoints(t3) << endl;

    // corner case, point 2,3 are equal?
    vector<Point> t4 = {
        Point(0,9),
        Point(138,429),
        Point(115,359),
        Point(115,359),
        Point(-30,-102),
        Point(230,709),
        Point(-150,-686),
        Point(-135,-613),
        Point(-60,-248),
        Point(-161,-481),
        Point(207,639),
        Point(23,79),
        Point(-230,-691),
        Point(-115,-341),
        Point(92,289),
        Point(60,336),
        Point(-105,-467),
        Point(135,701),
        Point(-90,-394),
        Point(-184,-551),
        Point(150,774)};
    cout << "t4: " << s.maxPoints(t4) << endl;

    vector<Point> t5 = {Point(1,1), Point(1,1), Point(1,1)};
    cout << "t5: " << s.maxPoints(t5) << endl;

    return 0;
}
