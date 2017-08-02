/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length
 */

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int count = 0;
    int r = 0, w = 0;
    int r1 = -1;
    while (r < numsSize) {
        /* always advance first num */
        if (r1 == -1) {
            r1 = r;
            r++;
            w++;
            count++;
            continue;
        }

        while (r < numsSize && nums[r] == nums[r1])
            r++;

        if (r < numsSize) {
            r1 = w;
            nums[w++] = nums[r++];
            count++;
        }
    }
    return count;
}

void main()
{
    int i;
    int n1[] = {1, 1};
    int r1 = removeDuplicates(n1, 2);
    
    for (i=0; i<r1; i++) {
        printf("%d ", n1[i]);
    }
    printf("\n");

    int n2[] = {1, 1, 2};
    int r2 = removeDuplicates(n2, 3);

    for (i=0; i<r2; i++) {
        printf("%d ", n2[i]);
    }
    printf("\n");

    int n3[] = {1, 2, 2};
    int r3 = removeDuplicates(n3, 3);

    for (i=0; i<r3; i++) {
        printf("%d ", n3[i]);
    }
    printf("\n");
}
