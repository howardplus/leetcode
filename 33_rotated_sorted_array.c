/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 */

#include <stdio.h>
#include <stdlib.h>

int bin_search(int *nums, int numsSize, int l, int r, int target)
{
    if (l <= r) {
        int mid = l + (r - l)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) {
            return bin_search(nums, numsSize, l, mid-1, target);
        } else {
            return bin_search(nums, numsSize, mid+1, r, target);
        }
    }
    return -1;
} 

int search(int* nums, int numsSize, int target)
{
    int prev;
    int i;
    for (i=0; i<numsSize; i++) {

        if (nums[i] == target) {
            return i;
        }

        if (i == 0) {
            prev = i;
        } else if (nums[i] < nums[prev]) {
            if (target > nums[prev]) {
                /* found pivot, but still too small, not found */
                return -1;
            } else {
                /* start binary search */
                int ret = bin_search(&nums[i], numsSize-i, 0, numsSize-i-1, target);
                if (ret == -1) {
                    return -1;
                } else {
                    return i + ret;
                }
            }
        }
    }

    return -1;
}

void main()
{
    int a1[] = {4, 5, 6, 7, 0, 1, 2};
    int r1 = search(a1, 7, 1);
    printf("%d\n", r1);
    r1 = search(a1, 7, 9);
    printf("%d\n", r1);
    r1 = search(a1, 7, 5);
    printf("%d\n", r1);

    int a2[] = {5, 1, 3};
    r1 = search(a2, 3, 3);
    printf("%d\n", r1);
}
