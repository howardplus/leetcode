/*
 * Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

Note:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() == 0)
			return true;

    	// a valid stack seq can only change direction the most once 
		unordered_map<int, int> m;
		for (auto i=0; i<pushed.size(); i++) {
			m[pushed[i]] = i;
		}

		// mark elements until the top is reached
		int i;
		for (i=0; i<popped.size(); i++) {
			int idx = m[popped[i]];
			if (idx == popped.size() - 1)
				break;
			pushed[idx] = -1;
		}
		
		// walk backward
		int j = pushed.size() - 1;
		for (i; i<popped.size(); i++) {
			if (popped[i] != pushed[j--]) return false;	
			while (j>=0 && pushed[j] == -1) j--;
		}

		return true;
    }
};

int main() {
	Solution s;

	auto t1 = vector<int>{1,2,3,4,5};
	auto t2 = vector<int>{4,5,3,2,1};
	auto t3 = vector<int>{4,3,5,1,2};
	cout << s.validateStackSequences(t1, t2) << endl;
	cout << s.validateStackSequences(t1, t3) << endl;

	auto t4 = vector<int>{1,0,2};
	auto t5 = vector<int>{2,1,0};
	cout << s.validateStackSequences(t4, t5) << endl;

	return 0;
}
