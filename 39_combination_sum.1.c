/*
 * https://leetcode.com/problems/combination-sum/description/
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *s1, const void *s2)
{
    return *(int*)s1 > *(int*)s2;
}

/* return 1 if found; 0 if not */
int find_comb(int *cand, int candSz, int target, int ***cols, int **colsSz, int *nCol)
{
    int ret = 0;
    int i;
    int x = cand[candSz-1];

    int *col;
    int colSz;
    int n = *nCol;

    /* is there a col size yet? */
    if (*colsSz == NULL) {
        *colsSz = (int*)malloc(1 * sizeof(int));
        (*colsSz)[0] = 0;
    }
    if (*cols == NULL) {
        *cols = (int**)malloc(1 * sizeof(int*));
        (*cols)[0] = NULL;
    }

    col = (*cols)[n]; 
    colSz = (*colsSz)[n];

    if (candSz == 0 || target < x) {
        (*colsSz)[n] = 0;
        return 0;
    } else if (target == x) {
        colSz++;
        col = (int*)realloc(col, colSz * sizeof(int));
        col[colSz-1] = x;

        (*cols)[*nCol] = col;
        (*colsSz)[*nCol] = colSz;
        (*nCol)++;

        /* add space */
        *cols = (int**)realloc(*cols, (*nCol + 1) * sizeof(int*));
        *colsSz = (int*)realloc(*colsSz, (*nCol + 1) * sizeof(int));
        return 1;
    } else {
        /* if multiple, take the multiple as first answer */
        if (target % x == 0) {
            int n = target / x;
            colSz += n;
            col = (int*)realloc(col, colSz * sizeof(int));
            for (i=0; i<n; i++)
                col[colSz-1-i] = x;

            (*cols)[*nCol] = col;
            (*colsSz)[*nCol] = colSz;
            (*nCol)++;

            /* add space */
            *cols = (int**)realloc(*cols, (*nCol + 1) * sizeof(int*));
            *colsSz = (int*)realloc(*colsSz, (*nCol + 1) * sizeof(int));

            ret = 1;
            
            /* remove 1 and keep going */
            for (i=1; i<n; i++) {
                target -= x;
                int *col1 = (int*)malloc((colSz-i) * sizeof(int));
                memcpy(col1, col, (colSz-i) * sizeof(int));

                (*cols)[*nCol] = col1;
                (*colsSz)[*nCol] = colSz-i;

                if (find_comb(cand, candSz-1, target, cols, colsSz, nCol) == 1) {
                    (*cols)[*nCol] = col1;
                    (*colsSz)[*nCol] = colSz-i;
                    (*nCol)++;

                    /* add space */
                    *cols = (int**)realloc(*cols, (*nCol + 1) * sizeof(int*));
                    *colsSz = (int*)realloc(*colsSz, (*nCol + 1) * sizeof(int));

                    ret = 1;
                } else {
                    (*colsSz)[n] = 0;
                }
            }
            
        } else {
            int rem = target - x;

            int *col1 = (int*)realloc(col, (colSz+1)*sizeof(int));
            col1[colSz] = x;

            (*cols)[*nCol] = col1;
            (*colsSz)[*nCol] = colSz+1;

            return find_comb(cand, candSz-1, rem, cols, colsSz, nCol);
        }
    }

    if (ret == 0) {
        (*colsSz)[n] = 0;
    }

    return ret;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    int i;
    int **cols = NULL;
    int *colsSz = NULL;
    int count = 0;

    qsort(candidates, candidatesSize, sizeof(int), comp); 

    for (i=0; i<candidatesSize; i++) {
        if (find_comb(candidates, i+1, target, &cols, &colsSz, &count) == 0) {
            free(cols[count]);
            cols[count] = NULL;
            colsSz[count] = 0;
        }
    }
    *columnSizes = colsSz;
    *returnSize = count;
    return cols;
}

void main()
{
    int i, j;
    int s1[] = {2, 6, 3, 7};
 //   int s1[] = {1, 2};
    int target = 27;

    int *cs1 = NULL;
    int rs1;
    int **r1 = combinationSum(s1, sizeof(s1)/sizeof(s1[0]), target, &cs1, &rs1);

    printf("count = %d\n", rs1);
    for (i=0; i<rs1; i++) {
        printf("[");
        for (j=0; j<cs1[i]; j++) {
            printf("%d ", r1[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}
