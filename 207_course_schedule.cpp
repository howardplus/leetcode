/*
 * https://leetcode.com/problems/course-schedule/description/
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        for (auto i=0; i<numCourses; i++) {
        
            auto visited = vector<bool>(numCourses, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (auto p : prerequisites) {
                    if (p.first == cur ) {
                        if (p.second == i)
                            return false;

                        if (!visited[p.second]) {
                            visited[p.second] = true;
                            q.push(p.second);
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    auto t1 = vector<pair<int, int>>{
        {1, 0}
    };

    cout << s.canFinish(2, t1) << endl;

    auto t2 = vector<pair<int, int>>{
        {1, 0},
        {0, 1}
    };

    cout << s.canFinish(2, t2) << endl;

    auto t3 = vector<pair<int, int>>{
        {0, 1},
        {0, 2},
        {1, 2}
    };

    cout << s.canFinish(3, t3) << endl;

    auto t4 = vector<pair<int, int>>{
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    cout << s.canFinish(4, t4) << endl;

    auto t5 = vector<pair<int, int>>{
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4},
        {2, 4},
        {3, 4},
        {4, 0}
    };

    cout << s.canFinish(5, t5) << endl;


    return 0;
}
