/*
 * https://leetcode.com/problems/combination-sum/description/
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void run(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {

        // either target is out, or size is out
        if (target == 0) {
            result.emplace_back(current);
            return;
        } else if (candidates.size() == 0) 
            return;

        // shift the candidates
        auto n = candidates[0];
        auto nc = vector<int>{begin(candidates)+1, end(candidates)};

        // accumulate until reaches target
        for (auto i=0; i<target/n; i++) {
            vector<int> copy{begin(current), end(current)};

            auto t = target;
            for (auto j=0; j<=i; j++) {
                t -= n;
                copy.emplace_back(n);
            }
            run(nc, t, copy, result);
        }

        // already over target, keep going
        run(nc, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        auto result = vector<vector<int>>{};
        auto current = vector<int>{};
        run(candidates, target, current, result);
        return result;
    }

    void print(vector<vector<int>>& r) {
        cout << "[" << endl;
        for (auto& s: r) {
            cout << "[";
            for (auto& n: s) {
                cout << n << " ";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
};

int main()
{
    Solution s;

    vector<int> s1{2, 6, 3, 7};
    auto r1 = s.combinationSum(s1, 7);
    s.print(r1);

    vector<int> s2{2, 3, 5};
    auto r2 = s.combinationSum(s2, 8);
    s.print(r2);

    return 0;
}
