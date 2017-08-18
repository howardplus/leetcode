/*
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helper(char ***list, int *sz, char *buf, int n, int l, int r)
{
    if (l == n && r == n) {
        buf[l+r] = '\0';
        (*sz)++;
        char **tmp = (char**)realloc(*list, ((*sz)+1) * sizeof(char*));
        *list = tmp;
        return;
    } else if (l == r) {
        buf[l+r] = '(';
        helper(list, sz, buf, n, l+1, r);
    } else if (l == n) {
        buf[l+r] = ')';
        helper(list, sz, buf, n, l, r+1);
    } else {
        /* 2 possibilities */
        char *buf1 = NULL;
        buf1 = (char*)malloc((n*2+1) * sizeof(char));
        memcpy(buf1, buf, (n*2+1) * sizeof(char));

        buf[l+r] = '(';
        helper(list, sz, buf, n, l+1, r);

        (*list)[*sz] = buf1;
        buf1[l+r] = ')';
        helper(list, sz, buf1, n, l, r+1);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    char **list = (char **)malloc(1 * sizeof(char*));
    int size = 0;

    list[0] = (char*)malloc((n*2+1) * sizeof(char));

    helper(&list, &size, list[0], n, 0, 0);

    *returnSize = size;
    return list;
}

int main()
{
    int i, sz;
    char **result = generateParenthesis(3, &sz);

    printf("size = %d\n", sz);
    for (i=0; i<sz; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
