/*
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 *
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 *
 * For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree. 
 * Each comma separated value in the string must be either an integer or a character '#' representing null pointer.  
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {

        // special case, single #
        if (preorder == "#")
            return true;

        stack<vector<char>> s;
        stringstream ss{preorder};
        char c;
        int val;
        auto done = false;
        while (!ss.eof()) {
            bool sentinel = false;
            ss >> val;
            if (ss.fail()) {
                ss.clear();
                ss >> c;
                sentinel = true;
            }

            if (done)
                return false;

            if (sentinel) {
                if (s.empty() || s.top().size() >= 3)
                    return false;

                s.top().push_back(c);

                while (!s.empty() && s.top().size() == 3) {
                    s.pop();
                    if (!s.empty()) {
                        s.top().push_back(c);
                    } else {
                        done = true;
                    }
                }

            } else {
                vector<char> v{(char)val};
                s.push(v);
            }

            // absorb comma
            ss >> c;
        }

        return s.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("9,#,#,#") << endl;
    cout << s.isValidSerialization("9,#,#,1,#,#") << endl;
    return 0;
}
