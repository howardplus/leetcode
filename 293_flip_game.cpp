/*
 * You are playing the folowing Flip Game with your friend. Given a string that
 * contains only these characters: + and -, you and your friend take turns to
 * flip two consecutive "++" into "--". The game ends when a person can no
 * longer make a move and therefore the other person will be the winner.
 *
 * Write a function to compute all possible states of the string after one
 * valid move.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for (auto i=0; i<s.length()-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                auto s1 = s;
                s1[i] = '-';
                s1[i+1] = '-';
                result.push_back(s1);
            }
        }
        return result;
    }
};
