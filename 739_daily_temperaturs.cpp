/*
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * Given a list of daily temperatures, produce a list that, for each day in the
 * input, tells you how many days you would have to wait until a warmer
 * temperature. If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        stack<int> s; /* stack of past indices smaller than current */
        vector<int> result;
        result.resize(temperatures.size());
        for (auto i=0; i<temperatures.size(); i++) {
            /* pop the indices that are smaller */
            while (!s.empty()) {
                auto idx = s.top();
                if (temperatures[idx] < temperatures[i]) {
                    result[idx] = i - idx;
                    s.pop();
                } else
                    break;
            }
            s.push(i);
        }

        return result;
    }
};

int main()
{
    Solution s;
    for (auto n: s.dailyTemperatures({73,74,75,71,69,72,76,73})) {
        cout << n << " ";
    }
    cout << endl;

    for (auto n: s.dailyTemperatures({34,80,80,34,34,80,80,80,80,34})) {
        cout << n << " ";
    }
    //[1,0,0,2,1,0,0,0,0,0]
    cout << endl;
    return 0;
}
