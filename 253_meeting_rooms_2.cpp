/*
 * Given an array of meeting time intervals consisting of start and end times:
 * [[s1,e1],[s2,e2]...]
 * find the minimum number of conference rooms required.
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort based on start time
        sort(begin(intervals), end(intervals),
                [](const vector<int>& l, const vector<int>& r) -> bool {
                    return l[0] < r[0];
                });

        // keep track of end time, prioritized on earliest one
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : intervals) {
            int start = i[0];
            int end = i[1];

            if (!pq.empty() && pq.top() <= start) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};

int main() {

    Solution s;

    vector<vector<int>> t1 = {{0,30}, {5,10}, {15,20}};
    cout << s.minMeetingRooms(t1) << endl;

    return 0;
}
