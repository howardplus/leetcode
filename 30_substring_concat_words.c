/*
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int sz = 0;
    int *result = NULL;
    int *buckets = (int*)malloc(wordsSize * sizeof(int));
    int i, n = 0;
    for (i=0; i<wordsSize; i++) {
        n += strlen(words[i]);
    }

    int offset = 0;
    while (s[offset+n-1] != 0) {
        
        char *dup = strndup(&s[offset], n);
        char *s1 = dup;

        /* check s1 contains all combinations of buckets */
        memset(buckets, 0, wordsSize * sizeof(int));
        int count = 0;
        while (count < wordsSize) {
            int found = 0, j;
            for (j=0; j<wordsSize; j++) {
                if (buckets[j] == 0 && !strncmp(s1, words[j], strlen(words[j]))) {
                    s1 += strlen(words[j]);
                    buckets[j] = 1;
                    count++;
                    found = 1;
                }
            }

            if (!found) {
                break;
            }
        }

        if (count == wordsSize) {
            sz++;
            result = realloc(result, sz * sizeof(int));
            result[sz-1] = offset;
        }

        offset++;
        free(dup);
    }

    *returnSize = sz; 
    return result;
}

void main()
{
    int i;
    char *s1 = "barfoothefoobarman";
    char *words1[] = {"foo", "bar"};

    int sz;
    int *r = findSubstring(s1, words1, 2, &sz);

    for (i=0; i<sz; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    char *s2 = "barfoofoobarthefoobarman";
    char *words2[] = {"bar","foo","the"};

    r = findSubstring(s2, words2, 3, &sz);

    for (i=0; i<sz; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    char *s3 = "wordgoodgoodgoodbestword";
    char *words3[] = {"word","good","best","good"};

    r = findSubstring(s3, words3, 4, &sz);

    for (i=0; i<sz; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}
