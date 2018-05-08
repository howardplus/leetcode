/*
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct CCount {
    char c;
    int count;
    CCount(): c('\0'), count(0) {}
    CCount(char c): c(c), count(1) {}
};

struct CCountComp {
    bool operator() (CCount& l, CCount& r) {
        return l.count < r.count;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, CCount> m;

        for (auto i=0; i<s.length(); i++) {
            char c = s[i];
            if (m.find(c) == end(m))
                m.insert(make_pair(c, CCount{c}));
            else
                m[c].count++;
        }

        priority_queue<CCount, vector<CCount>, CCountComp> pq; 
        
        for (auto e: m) {
            pq.push(e.second);
        }

        stringstream ss;
        while (!pq.empty()) {
            for (auto i=0; i<pq.top().count; i++)
                ss << pq.top().c;
            pq.pop();
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
