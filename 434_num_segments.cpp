/*
 * https://leetcode.com/problems/number-of-segments-in-a-string/
 *
 * Count the number of segments in a string, where a segment is 
 * defined to be a contiguous sequence of non-space characters.
 */
class Solution {
public:
    int countSegments(string s) {
        enum {
            BEGIN = 0,
            SPACE,
            COUNT
        } st = BEGIN;
        
        int n = 0;
        for (auto c : s) {
            switch (st) {
            case BEGIN:
                if (c == ' ')
                    st = SPACE;
                else {
                    n++;
                    st = COUNT;
                }
                break;
            case SPACE:
                if (c == ' ')
                    continue;
                else {
                    n++;
                    st = COUNT;
                }
                break;
            case COUNT:
                if (c == ' ')
                    st = SPACE;
                break;
            }
        }
        
        return n;
    }
};

