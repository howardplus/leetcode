/*
 * https://leetcode.com/problems/largest-number/description/
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> vs;
        for (auto n: nums)
            vs.push_back(to_string(n));

        sort(begin(vs), end(vs), [](const string &a, const string &b) -> bool {
            return a+b > b+a;
        });

        string s{""};
        for (auto i : vs)
            s.append(i);
        return s[0] == '0' ? "0" : s;
    }
};

int main()
{
    Solution s;

    auto v1 = vector<int>{200,30,4};
    cout << s.largestNumber(v1) << endl;

    auto v2 = vector<int>{121,12};
    cout << s.largestNumber(v2) << endl;

    auto v3 = vector<int>{128,12};
    cout << s.largestNumber(v3) << endl;

    auto v4 = vector<int>{0,0};
    cout << s.largestNumber(v4) << endl;

    return 0;
}
