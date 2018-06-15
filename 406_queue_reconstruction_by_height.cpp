/*
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using Pair = pair<int, int>;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(begin(people), end(people),
            [](const Pair& x, const Pair& y) -> bool {
                return x.first > y.first || (x.first == y.first && x.second < y.second);
            });

        // starting from index 1, sort them to position 
        for (auto i=1; i<people.size(); i++) {
            // always look to the front only
            int j = i;
            int target = people[j].second;
            while (j > target) {
                swap(people[j], people[j-1]);
                j--;
            }
        }

        return people;
    }
};

int main() {
    Solution s;

    vector<Pair> t1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    auto r1 = s.reconstructQueue(t1);
    for (auto i : r1) {
        cout << i.first << "," << i.second << endl;
    }

    return 0;
}
