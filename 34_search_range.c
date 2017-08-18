/*
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <stdio.h>
#include <stdlib.h>

int bin_search(int *nums, int l, int r, int target)
{
    if (l <= r) {
        int mid = l + (r-l)/2;  
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return bin_search(nums, mid+1, r, target);
        else
            return bin_search(nums, l, mid-1, target);
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    int r = bin_search(nums, 0, numsSize-1, target);
    if (r == -1) {
        ret[0] = -1;
        ret[1] = -1;
    } else {
        /* found it, now move left and right to find start/end */
        int start = r;
        while ((start >= 0) && (nums[start-1] == nums[start]))
            start--;

        if (start < 0)
            start = 0;
        ret[0] = start;

        int end = r;
        while ((end < numsSize) && (nums[end+1] == nums[end]))
            end++;

        if (end >= numsSize)
            end = numsSize-1;
        ret[1] = end;
    }
    return ret;
}

void main()
{
    int i;
    int t1[] = {0, 0, 0, 1, 2, 3};
    int s;
    int *r1 = searchRange(t1, sizeof(t1)/sizeof(t1[0]), 0, &s);
    for (i=0; i<s; i++)
    {
        printf("%d ", r1[i]);
    }
    printf("\n");

    int t2[] = {5, 7, 7, 8, 8, 10};
    int *r2 = searchRange(t2, sizeof(t2)/sizeof(t2[0]), 8, &s);
    for (i=0; i<s; i++)
    {
        printf("%d ", r2[i]);
    }
    printf("\n");
}
