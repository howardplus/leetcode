/*
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * Given an input string, reverse the string word by word.
 */

#include <stdio.h>
#include <string.h>

void reverseWords(char *s)
{
    // reverse the whole string    
    int i = 0;
    int j = strlen(s)-1;
    // start with first non-space character
    while (s[i] == ' ')
        i++;

    while (i < j) {
        char tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }

    // reverse each word
    i = 0;
    while (s[i] == ' ')
        i++;

    int offset = i;
    int spaces = 0;
    int is_space = 0;
    for (j=i; j<strlen(s)+1; j++) {
      //  printf("=> j=%d %c; spaces=%d\n", j, s[j], spaces);
        if (s[j] == ' ' || s[j] == '\0') {
            if (is_space) {
                spaces++;
                continue;
            }

            is_space = 1;
            int end = (s[j] == '\0');

            // flip between i and j
            int a = i - offset - spaces;
            int b = j-1;
     //       printf("=> i=%d j=%d a=%d %c; b=%d %c\n", i, j, a, s[a], b, s[b]);
            while (a < b) {
                char tmp = s[a];
                s[a++] = s[b];
                s[b--] = tmp;
            }

            i = j+1;
            while (s[i] == ' ')
                i++;

            if (end)
                s[j-offset-spaces] = '\0';
        } else {
            is_space = 0;
        }
    }
}

int main()
{
    //char buf[200] = "   a   b  c d   e  ";
    char buf[200] = "    the    sky is blue ";
    printf("#%s#\n", buf);
    reverseWords(buf);
    printf("#%s#\n", buf);
    return 0;
}
