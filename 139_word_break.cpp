/*
 * https://leetcode.com/problems/word-break/description/
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool hasWord(const string& s, vector<string>& wordDict, map<string, bool>& m) {
        for (auto w : wordDict) {
            if (s == w) {
                m[s] = true;
                return true;
            }
        }
        m[s] = false;
        return false;
    }

    bool wordBreak2(string s, vector<string>& wordDict, map<string, bool>& m) {
        if (m.find(s) != end(m))
            return m[s];
        else if (hasWord(s, wordDict, m))
            return true;

        for (auto i=1; i<s.length(); i++) {
            auto first = string(begin(s), begin(s)+i);
            auto second = string(begin(s)+i, end(s));
            if (hasWord(second, wordDict, m) && wordBreak2(first, wordDict, m))
                return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> m;
        return wordBreak2(s, wordDict, m);
    }

};

int main()
{
    Solution s;

    // test1
    // s = "leetcode", wordDict = ["leet", "code"]
    auto d1 = vector<string>{"leet", "code"};
    cout << s.wordBreak("leetcode", d1) << endl;
    
    // test2
    // s = "applepenapple", wordDict = ["apple", "pen"]
    auto d2 = vector<string>{"apple", "pen"};
    cout << s.wordBreak("applepenapple", d2) << endl;
    
    // test3
    // s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    auto d3 = vector<string>{"cats", "dog", "sand", "and", "cat"};
    cout << s.wordBreak("catsandog", d3) << endl;

    return 0;
}

