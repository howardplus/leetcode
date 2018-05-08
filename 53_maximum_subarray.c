/*
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6
 */
#include <stdio.h>

#define MAX(i,j)  ((i) > (j) ? (i) : (j))

int maxSubArray(int* nums, int numsSize)
{
    int i;
    int max_so_far, max_ending_here;
    max_so_far = max_ending_here = nums[0];
    for (i=1; i<numsSize; i++) {
        max_ending_here = MAX(nums[i], max_ending_here + nums[i]);
        max_so_far = MAX(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void main()
{
    int t1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int len1 = sizeof(t1)/sizeof(t1[0]);
    printf("%d\n", maxSubArray(t1, len1));
}
