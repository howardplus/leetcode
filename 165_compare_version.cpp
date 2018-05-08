/*
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0.
 *
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 *
 * example:
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 */

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        queue<int> token1, token2;

        stringstream ss1{version1};
        stringstream ss2{version2};
        string temp;

        while(getline(ss1, temp, '.'))
            token1.push(atoi(temp.c_str()));

        while(getline(ss2, temp, '.'))
            token2.push(atoi(temp.c_str()));

        auto sz = max(token1.size(), token2.size());
        for (auto i=0; i<sz; i++) {
            if (token1.size() == 0)
                token1.push(0);
            if (token2.size() == 0)
                token2.push(0);

            int v1 = token1.front();
            token1.pop();
            int v2 = token2.front();
            token2.pop();
            if (v1 < v2)
                return -1;
            else if (v1 > v2)
                return 1;
        }

        return 0;
    }
};

int main()
{
    Solution s;

    cout << s.compareVersion("01", "1") << endl;
    cout << s.compareVersion("0.1", "1.1") << endl;
    cout << s.compareVersion("1.1", "1.2") << endl;
    cout << s.compareVersion("3.10", "2.12") << endl;
    cout << s.compareVersion("3.10", "3.37") << endl;
    cout << s.compareVersion("3.10", "3.10") << endl;
    cout << s.compareVersion("1.0.1", "3.1") << endl;

    return 0;
}
