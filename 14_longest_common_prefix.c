#include <stdlib.h>
#include <stdio.h>

#define MIN(x,y) ((x)<(y) ? (x) : (y))

char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (strsSize == 0)
        return "";

    char *str;
    char *str0 = strs[0];
    int lcp = strlen(str0);
    int i, j;
    for (i=1; i<strsSize; i++) {
        str = strs[i];
        int len = MIN(lcp, strlen(str));

        for (j=0, lcp=0; j<len; j++, lcp++) {
            if (str[j] != str0[j]) {
                lcp = MIN(j, lcp);
                break;
            }
        }
    }

    str = malloc(lcp+1);
    strncpy(str, str0, lcp);
    str[lcp] = '\0';
    return str;
}

int main()
{
    char *t1[] = {
        "abcdefg",
        "abcde",
        "abcd23",
        "abcdyz"
    };
    printf("%s\n", longestCommonPrefix(t1, 4));
    return 0;
}
