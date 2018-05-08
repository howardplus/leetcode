/*
 * https://leetcode.com/problems/word-search/description/
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool path_exist(vector<vector<char>>& board, vector<vector<char>> visited, string word, int m, int n, int idx)
    {
        if (idx == word.size())
            return true;

        char c = word[idx];
        if (m != 0 && visited[m-1][n] && board[m-1][n] == c) {
            visited[m-1][n] = 0;
            if (path_exist(board, visited, word, m-1, n, idx+1))
                return true;
            else
                visited[m-1][n] = 1;
        }
        if (m != board.size()-1 && visited[m+1][n] && board[m+1][n] == c) {
            visited[m+1][n] = 0;
            if (path_exist(board, visited, word, m+1, n, idx+1))
                return true;
            else
                visited[m+1][n] = 1;
        }
        if (n != 0 && visited[m][n-1] && board[m][n-1] == c) {
            visited[m][n-1] = 0;
            if (path_exist(board, visited, word, m, n-1, idx+1))
                return true;
            else
                visited[m][n-1] = 1;
        }
        if (n != board[0].size()-1 && visited[m][n+1] && board[m][n+1] == c) {
            visited[m][n+1] = 0;
            if (path_exist(board, visited, word, m, n+1, idx+1))
                return true;
            else
                visited[m][n+1] = 1;
        }

        cout << "fail @" << idx << ": " << m << "," << n << endl;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        vector<vector<char>> visited = board;

        for (int m=0; m<board.size(); m++) {
            for (int n=0; n<board[0].size(); n++) {

                if (word[0] == board[m][n]) {
                    visited[m][n] = 0;
                    cout << "trying " << m << "," << n << endl;
                    if (path_exist(board, visited, word, m, n, 1))
                        return true;
                    else
                        visited = board;
                }

            }
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> t1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}}; 

    cout << s.exist(t1, "ABCCED") << endl;
    cout << s.exist(t1, "SEE") << endl;
    cout << s.exist(t1, "ABCB") << endl;

    vector<vector<char>> t2 = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}};

    cout << s.exist(t2, "ABCESEEEFS") << endl;

    return 0;
}
