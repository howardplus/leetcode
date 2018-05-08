/*
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int compute(int x, int y, char op) {
        if (op == '+')
            return x+y;
        else if (op == '-')
            return x-y;
        else if (op == '*')
            return x*y;
        else
            return 0; /* should not happen */
    }

    vector<int> compute(const vector<int>& x, const vector<int>& y, char op) {
        vector<int> r;
        for (auto i: x)
            for (auto j: y)
                r.push_back(compute(i, j, op));
        return r;
    }

    void computeAll(const vector<int>& nums, const vector<char>& ops, vector<int>& results)
    {
        if (ops.size() == 0) {
            results.push_back(nums[0]);
            return;
        }

        // take left and right
        for (int i=0; i<ops.size(); i++) {
            char op = ops[i];

            // left = 0:i
            vector<int> left_nums{begin(nums), begin(nums)+i+1};
            vector<char> left_ops{begin(ops), begin(ops)+i};

            vector<int> lresults;
            computeAll(left_nums, left_ops, lresults);

            // right = i:size-1
            vector<int> right_nums{begin(nums)+i+1, end(nums)};
            vector<char> right_ops{begin(ops)+i+1, end(ops)};

            vector<int> rresults;
            computeAll(right_nums, right_ops, rresults);

            auto r = compute(lresults, rresults, op);
            results.insert(end(results), begin(r), end(r));
        }
    }

    vector<int> diffWaysToCompute(string input) {
        istringstream ss{input};

        vector<int> nums;
        vector<char> ops;
        while (!ss.eof()) {
            int n;
            char op;
            ss >> n;
            nums.push_back(n);
            if (!ss.eof()) {
                ss >> op;
                ops.push_back(op);
            }
        }

        vector<int> r;
        computeAll(nums, ops, r);
        return r;
    }
};

int main()
{
    Solution s;

    auto t1 = s.diffWaysToCompute("2*3-4*5");
    for (auto i: t1) {
        cout << i << endl;
    }

    return 0;
}
