/*
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie {
    int val;
    vector<Trie*> children;
    Trie(): val(0) {}
    Trie(int v): val(v) {}
};

class Solution {
public:
    int lengthFromHere(Trie *root, const vector<int>& v, int idx) {
        Trie *n = root;
        auto len = 0;
        for (auto i=idx; i<v.size(); i++) {
            auto found = false;
            for (auto c: n->children) { 
                if (v[i] == c->val) {
                    len++;
                    n = c;
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }
        return len;
    }

    int findLength(const vector<int>& A, const vector<int>& B) {
        Trie *root = new Trie;

        /* suffix trie from A */ 
        for (int i = A.size()-1; i>=0; i--) {
            auto n = root;
            for (auto j = i; j < A.size(); j++) {
                auto v = A[j];  
                auto found = false;
                for (auto c: n->children) {
                    if (c->val == v) {
                        n = c;
                        found = true;
                        break;
                    }
                }

                if (!found) {
             //       cout << "add " << v << " to " << n->val << endl;
                    auto n1 = new Trie(v);
                    n->children.push_back(n1);
                    n = n1; 
                }
            }
            //cout << "---" << endl;
        }

        /* find B in trie */
        auto length = 0;
        for (auto i=0; i<B.size(); i++) {
            auto l = lengthFromHere(root, B, i);
            length = max(length, l);
        }

        return length;
    }
};

int main()
{
    Solution s;
    cout << s.findLength({1,2,3,2,1}, {3,2,1,4,7}) << endl;
    return 0;
}
