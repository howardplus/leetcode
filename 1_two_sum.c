/*
 * https://leetcode.com/problems/two-sum/description/
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashentry {
    int val;
    int index;
    struct hashentry *next;
} hashentry;

#define SIZE 100

typedef struct hashmap {
    struct hashentry *buckets[SIZE];
} hashmap;

void hashmap_push(hashmap *map, int val, int index)
{
    unsigned key = (unsigned)val % SIZE;
    hashentry *e = (hashentry*)malloc(sizeof(hashentry));
    e->val = val;
    e->index = index;

    // insert to front
    e->next = map->buckets[key];
    map->buckets[key] = e;
}

int hashmap_find(hashmap *map, int val)
{
    unsigned key = (unsigned)val % SIZE;
    hashentry *e;
    for (e=map->buckets[key]; e != NULL; e = e->next) {
        if (e->val == val) {
            return e->index;
        }
    }
    /* not found */
    return -1;
}

int* two_sum(int* nums, int n, int target)
{
    int i;
    hashmap map;
    memset(&map, 0, sizeof(hashmap));

    for (i=0; i<n; i++) {
        int need = target - nums[i];
        int idx = hashmap_find(&map, need);
        if (idx != -1) {
            int *r = (int*)malloc(2*sizeof(int));
            r[0] = idx;
            r[1] = i;
            return r;
        }
        hashmap_push(&map, nums[i], i);
    }
    return NULL;
}

int main()
{
    int test1[] = {-3, 4, 3, 90};
    int *r1 = two_sum(test1, 4, 0);
    printf("%d %d\n", r1[0], r1[1]);
    free(r1);

    int test2[] = {2, 1, 11, 8, 5};
    int *r2 = two_sum(test2, 5, 7);
    printf("%d %d\n", r2[0], r2[1]);
    free(r2);

    return 0;
}
