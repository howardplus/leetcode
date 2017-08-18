/*
 * https://leetcode.com/problems/permutations/description/
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ctx {
    int **result;   /* end result */
    int size;       /* array size */
    int *mask;      /* use mask */
    int *buf;

    int *nums;
    int numsSize;
};

void permute_one(struct ctx *c, int idx)
{
    int i;

    /* when it's done */
    if (idx == c->numsSize) {
        c->result = (int**)realloc(c->result, sizeof(int*) * (c->size+1));
        c->result[c->size] = (int*)malloc(sizeof(int) * c->numsSize); 

        for (i=0; i<c->numsSize; i++)
            c->result[c->size][i] = c->buf[i];

        c->size++;
        return;
    }

    /* loop through all the unused values and write it out */
    for (i=0; i<c->numsSize; i++) {
        if (!c->mask[i]) {
            /* write the current valu */
            c->buf[idx] = c->nums[i];

            c->mask[i] = 1;
            permute_one(c, idx+1);
            c->mask[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    int *mask = (int*)calloc(numsSize, sizeof(int));
    int *buf = (int*)malloc(numsSize * sizeof(int));

    struct ctx c = {.result=NULL, .size=0, .nums=nums, .numsSize=numsSize, .mask=mask, .buf=buf};

    permute_one(&c, 0);

    free(mask);
    free(buf);

    *returnSize = c.size;
    return c.result;
}

void main()
{
    int t1[] = {1, 2, 3, 4};
    int sz1 = sizeof(t1)/sizeof(t1[0]);
    int s1;
    int **r1 = permute(t1, sz1, &s1);

    int i;
    printf("%d\n", s1);
    for (i=0; i<s1; i++) {
        printf("[");
        int j;
        for (j=0; j<sz1; j++) {
            printf("%d ", r1[i][j]);
        }
        printf("]\n");
    }
}
