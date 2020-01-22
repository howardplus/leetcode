#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

		auto len = s.length();	

        auto trail = 0;
        while (s[len-1] == ' ') {
            len--;
            trail++;
        }

		while (len) {
			if (s[len-1] == ' ')
				break;
			len--;
		}

		return s.length() - len - trail;
    }
};

int main() {
	Solution s;

	cout << s.lengthOfLastWord("") << endl;
	cout << s.lengthOfLastWord("Hello World") << endl;
	cout << s.lengthOfLastWord("a ") << endl;

	return 0;
}
