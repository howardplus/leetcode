/*
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        if (pairs.size() == 0)
            return 0;

        sort(begin(pairs), end(pairs), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });

        auto count = 1;
        auto end = pairs[0][1];

        for (auto i=1; i<pairs.size(); i++) { 
            auto p = pairs[i];
            if (p[0] <= end)
                continue;
           
            count++; 
            end = p[1];
        } 
        
        return count;
    }
};

int main()
{
    Solution s;

    auto t1 = vector<vector<int>>{{2,3},{1,2},{3,4}};
    cout << s.findLongestChain(t1) << endl; 

    auto t2 = vector<vector<int>>{{2,3},{1,4},{4,5},{6,7}};
    cout << s.findLongestChain(t2) << endl; 

    auto t3 = vector<vector<int>>{{1,7},{1,2},{3,4},{5,6}};
    cout << s.findLongestChain(t3) << endl; 

    return 0;
}
