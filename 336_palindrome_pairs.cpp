/*
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(const vector<string>& words) {
            
    }
};

int main()
{
    Solution s;

    auto r1 = s.palindromePairs({"bat", "tab", "cat"});
    for (auto i: r1) {
        cout << "[";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
