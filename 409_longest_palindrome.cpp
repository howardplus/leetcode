#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
    	unordered_map<char, int> m; 
		for (auto c : s) {
			if (m.find(c) == end(m))
				m[c] = 1;
			else
				m[c]++;
		}

		int sz = 0;
		bool oddUsed = false;
		for (auto kv : m) {
			if (kv.second % 2 == 0)
				sz += kv.second;	
			else {
				sz += (kv.second >> 1) << 1;	
				if (!oddUsed) {
					oddUsed = true;
					sz++;
				}
			}
		}

		return sz;
    }
};

int main() {
	Solution s;
	cout << s.longestPalindrome("abccccdd") << endl;
	return 0;
}
