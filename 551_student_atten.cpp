/*
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int consL = 0;
        for (auto i=0; i<s.length(); i++) {
            if (s[i] == 'L')
                consL++;
            else
                consL = 0;

            if (s[i] == 'A')
                countA++;

            if (countA > 1)
                return false;
            if (consL > 2)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
    return 0;
}
