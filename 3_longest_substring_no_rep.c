/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 */
#include <stdio.h>
#include <string.h>

int len_longest_substring(char *s)
{
    int used[256] = {0};
    int count = 0, pos = 0;
    int max = 0;
    while (s[pos]) {
        int key = s[pos];
        if (used[key]) {
            if (count > max)
                max = count;
            pos -= (count - used[key]);
            /* reset count and used map */
            count = 0;
            memset(used, 0, sizeof(used));
        } else {
            count++;
            used[key] = count;
            pos++;
        }
    }

    if (count > max)
        max = count;

    return max;
}

int main()
{
    char *s1 = "abcabcbb";
    printf("%d\n", len_longest_substring(s1));

    char *s2 = "bbbbb";
    printf("%d\n", len_longest_substring(s2));

    char *s3 = "pwwkew";
    printf("%d\n", len_longest_substring(s3));

    char *s4 = "dvdf";
    printf("%d\n", len_longest_substring(s4));
}
