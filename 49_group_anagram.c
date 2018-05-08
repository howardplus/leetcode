/*
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAnagram(char *s1, char *s2)
{
    int hash[] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
    int s1_hash = 1, s2_hash = 1;
    int i;
    if (strlen(s1) != strlen(s2)) return 0;

    for (i=0; i<strlen(s1); i++) {
        s1_hash *= hash[s1[i]-'a'];
        s2_hash *= hash[s2[i]-'a'];
    }

    return (s1_hash == s2_hash);
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize)
{
    int i;
    int *mask = (int*)calloc(strsSize, sizeof(int));

    char ***result = NULL;
    int *colSz = NULL;
    int retSz = 0;

    for (i=0; i<strsSize; i++) {
        if (mask[i] != 0) continue;

        char *str = strs[i];

        /* for a new column, create memory first */
        result = (char***)realloc(result, (retSz+1) * sizeof(int**));
        result[retSz] = NULL;
        colSz = (int*)realloc(colSz, (retSz+1) * sizeof(int));
        colSz[retSz] = 0;
        retSz++;

        int idx = retSz - 1;
        int j;
        for (j=i; j<strsSize; j++) {
            if (i == j || isAnagram(str, strs[j])) {
                /* add to current col */
                colSz[idx]++;
                result[idx] = (char**)realloc(result[idx], colSz[idx] * sizeof(int*));
                int strIdx = colSz[idx]-1;
                result[idx][strIdx] = strs[j];
                mask[j] = 1;
            }
        }
    }

    *returnSize = retSz;
    *columnSizes = colSz;
    return result;
}

void main()
{
    char *s1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int len1 = sizeof(s1)/sizeof(s1[0]);
    char ***r1;
    int *col1;
    int rs1;

    r1 = groupAnagrams(s1, len1, &col1, &rs1);
    printf("groups = %d\n", rs1);

    int i, j;
    for (i=0; i<rs1; i++) {
        for (j=0; j<col1[i]; j++) {
            printf("%s ", r1[i][j]);
        }
        printf("\n");
    }
}
