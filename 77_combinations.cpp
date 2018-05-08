/*
 * https://leetcode.com/problems/combinations/description/
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    vector<vector<int>> comb;

    void combine_one(vector<int>& v, int cur, int left) {
        if (left == 0)
            return;

        // either use cur or not
        auto v_copy = v;

        v.push_back(cur);
        combine_one(v, cur+1, left-1);
        comb.push_back(v);

        combine_one(v_copy, cur+1, left-1); 
        comb.push_back(v_copy);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combine_one(v, 1, k);
        return comb;
    }
};

int main()
{
    Solution s;
    auto r1 = s.combine(4, 2);

    for (auto v : r1) {
        cout << "[";
        for (auto c : v) {
            cout << c << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
