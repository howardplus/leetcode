/*
 * Write a function to generate the generalized abbreviation of a word.
 *
 * <n-chars> rest of the words
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate(string& str, int idx, string currStr, int count, vector<string>& result) {
        if (idx >= str.length()) {
            if (count)
                currStr += to_string(count);
            result.push_back(currStr);
            return;
        }

        // #1 keep the letter
        string s1 = currStr;
        if (count > 0)
            s1 += to_string(count);
        s1 += str[idx];
        generate(str, idx+1, s1, 0, result);

        // #2 continue to count
        generate(str, idx+1, currStr, count+1, result);
    }

    vector<string> generateAbbr(string str) {
        vector<string> v;
        generate(str, 0, "", 0, v);
        return v;
    }
};

int main() {
    Solution s;

    auto r1 = s.generateAbbr("word");
    for (auto r : r1) {
        cout << r << endl;
    }

    return 0;
}
