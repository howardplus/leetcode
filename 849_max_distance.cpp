/*
 * n a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. 
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 *
 * Return that maximum distance to closest person.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first = -1, last = -1;
        int maxDist = 0;
        int sz = seats.size();
        for (int i=0; i<sz; i++) {
            if (seats[i] == 1) {
                if (first == -1)
                    first = i;

                if (last != -1)
                    maxDist = max(maxDist, i-last);

                last = i;
            }
        }

        return max(maxDist/2, max(first, sz-last-1));
    }
};

int main() {
    Solution s;

    vector<int> t1 = {1,0,0,0,1,0,1};
    cout << s.maxDistToClosest(t1) << endl;

    vector<int> t2 = {1,0,0,0};
    cout << s.maxDistToClosest(t2) << endl;

    vector<int> t3 = {0,1};
    cout << s.maxDistToClosest(t3) << endl;

    return 0;
}
