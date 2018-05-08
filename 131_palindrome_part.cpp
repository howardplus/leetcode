/*
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s)
    {
        auto i = 0;
        auto j = s.length()-1;

        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    bool partitionFunc(const string &s, vector<vector<string>> &list)
    {
        if (s.size() == 0)
            return true;

        bool ret = false;
        for (auto i=s.size(); i>0; i--) {
            auto s1 = s.substr(0, i);
            if (isPalindrome(s1)) {
                //cout << "found palindrome on " << s1 << endl;

                // start a new list        
                vector<vector<string>> l1;

                // try and find palindrome on the rest of the partition
                auto s2 = s.substr(i, s.length());
                if (partitionFunc(s2, l1)) {

                    //cout << "got it on " << s1 << endl;

                    vector<string> v;
                    if (l1.size() == 0) {
                        l1.insert(begin(l1), v);
                    }

                    // add myself to the list
                    for (auto &x : l1) {
                        x.insert(begin(x), s1);
                    }

                    //cout << "l1 = " << l1.size() << endl;

                    // add the new list to me
                    list.insert(end(list), begin(l1), end(l1));
                    ret = true;
                }
            }
        }

        return ret;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> list;
        partitionFunc(s, list);
        return list;
    }
};

int main()
{
    Solution s;

    auto t1 = s.partition("aababba");
    cout << t1.size() << endl;
    for (auto i : t1) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
