/*
 * Given a rows x cols screen and a sentence represented by a list of non-empty
 * words, find how many times the given sentence can be fitted on the screen.
 *
 * Note:
 * 1. a word cannot be split into two lines.
 * 2. The order of words in the sentence must remain unchanged.
 * 3. Two consecutive words in a line must be separated by a single space.
 * 4. Total words in the sentence won't exceed 100.
 * 5. Length of each word is greater than 0 and won't exceed 10.
 * 6. 1 <= rows, cols <= 20000
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wordsFitting(const vector<string>& sentence, int rows, int cols) {
        vector<int> lengths;
        for (auto w : sentence) {
            lengths.emplace_back(w.length());
        }

        int count = 0; // total sentence fitted
        int i = 0; // word index
        int r = 0, c = 0;
        while (r < rows) {
            if (c + lengths[i] == cols) {
                c = 0;
                i++;
                r++;
            } else if (c + lengths[i] < cols) {
                c += lengths[i] + 1; // plus space
                i++;
            } else {
                c = 0;
                r++;
            }

            if (i == lengths.size()) {
                count++;
                i = 0;
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    cout << s.wordsFitting({"hello", "world"}, 2, 8) << endl; // 1
    cout << s.wordsFitting({"a", "bcd", "e"}, 3, 6) << endl; // 2
    cout << s.wordsFitting({"I", "had", "apple", "pie"}, 4, 5) << endl; // 1
    return 0;
}
