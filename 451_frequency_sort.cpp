/*
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 */
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <sstream>

using namespace std;

/*
 * 1. Put each character into array of its slot
 * 2. Sort the array
 * 3. Retrieve each character, and append into a new string.
 */
struct CharCount {
    char c;
    int count;
    CharCount(): c(0), count(0) {}
    CharCount(char x, int y): c(x), count(y) {}
};

class Solution {
public:
    string frequencySort(string s) {
        array<CharCount, 256> characters;

        for (auto c : s) {
            characters[c].c = c;
            characters[c].count++;
        }

        sort(begin(characters), end(characters),
                [](const CharCount& l, const CharCount& r) -> bool {
                    return l.count > r.count; 
                });

        stringstream ss;
        for (auto cc : characters) {
            for (auto i=0; i<cc.count; i++) {
                ss << cc.c;
            }
        }
        return ss.str();
    }
};

int main()
{
    Solution s;
    cout << s.frequencySort("tree") << endl;
    cout << s.frequencySort("cccaaa") << endl;
    cout << s.frequencySort("Aabb") << endl;
    return 0;
}
