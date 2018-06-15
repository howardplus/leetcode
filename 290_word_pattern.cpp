/*
 * https://leetcode.com/problems/word-pattern/description/
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // tokenize str
        istringstream iss(str);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }

        if (pattern.size() != tokens.size())
            return false;

        unordered_map<char, string> m; 
        unordered_map<string, char> m_rev;
    
        for (auto i=0; i<pattern.length(); i++) {
            auto c = pattern[i];
            if (m.find(c) == end(m)) {
                m[c] = tokens[i];
                if (m_rev.find(tokens[i]) == end(m_rev))
                    m_rev[tokens[i]] = c;
                else
                    return false;
            } else {
                if (m[c].compare(tokens[i]) != 0)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;

    return 0;
}
