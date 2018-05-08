/*
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 */
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct kv {
    int key;
    int value;
    kv(int k, int v): key(k), value(v) {}
};

struct kvcomp {
    bool operator() (const kv& l, const kv& r) {
        return l.value < r.value;
    }
};

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, kv*> m; 
        for (auto n: nums) {
            if (m.find(n) == m.end())
                m[n] = new kv(n, 0);
            else
                m[n]->value++;
        }

        priority_queue<kv, vector<kv>, kvcomp> pq;        
        for (auto i: m) {
            pq.push(*i.second);
            delete i.second;
        }

        vector<int> result;
        while (k--) {
            result.push_back(pq.top().key);
            pq.pop();
        }
    
        return result; 
    }
};

int main()
{
    Solution s;
    for (auto i: s.topKFrequent({1,1,1,2,2,3}, 2)) {
        cout << i << endl;
    }
    
    return 0;
}
