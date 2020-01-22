#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";	

		size_t idx = strs[0].length();
		vector<char> v{};
		for (auto c: strs[0]) {
			v.push_back(c);
		}

		for (auto i=1; i<strs.size(); i++) {
			idx = min(idx, strs[i].length());
			for (auto j=0; j<strs[i].length(); j++) {
				if (j >= idx)
					break;

				if (strs[i][j] != v[j]) {
					idx = j;
					break;
				}
			}
		}

		return string{begin(v), begin(v)+idx};
    }
};

int main() {
	Solution s;

    vector<string> t1 = {
        "abcdefg",
        "abcde",
        "abcd23",
        "abcdyz"
    };
    cout << s.longestCommonPrefix(t1) << endl;

    vector<string> t2 = {
		"flower",
		"flow",
		"flight"
    };
    cout << s.longestCommonPrefix(t2) << endl;

    vector<string> t3 = {
		"aa",
		"a"
    };
    cout << s.longestCommonPrefix(t3) << endl;

    return 0;
}
