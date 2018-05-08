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
    int len = temperatures.size();
        if (len == 0) return {};
        vector<int> res(len, 0);
        stack<int> stk;
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    for (auto n: s.dailyTemperatures({34,80,80,34,34,80,80,80,80,34})) {
        cout << n << " ";
    }
    //[1,0,0,2,1,0,0,0,0,0]
    cout << endl;
    return 0;
}
