/*
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 */
#include <stdio.h>

char* simplifyPath(char* path)
{
    return path; 
}

void main()
{
    char p1[] = "/home/";
    printf("%s\n", simplifyPath(p1));
}
