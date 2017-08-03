/*
 * https://leetcode.com/problems/rotate-image/description/
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 */

#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    int i, j;
    int **m1 = (int**)malloc(matrixRowSize * sizeof(int*));        
    for (i=0; i<matrixRowSize; i++) {
        m1[i] = (int*)malloc(matrixColSize * sizeof(int)); 
    }

    for (i=0; i<matrixRowSize; i++) {
        for (j=0; j<matrixColSize; j++) {
            m1[j][matrixRowSize-1-i] = matrix[i][j];
        }
    }

    for (i=0; i<matrixRowSize; i++) {
        for (j=0; j<matrixColSize; j++) {
            matrix[i][j] = m1[i][j];
        }
    }
}

void print(int **matrix, int n)
{
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i;
    int **m1;
    m1 = (int**)malloc(3 * sizeof(int*));
    for (i=0; i<3; i++) {
        m1[i] = (int*)malloc(3 * sizeof(int));
        m1[i][0] = i*3+1;
        m1[i][1] = i*3+2;
        m1[i][2] = i*3+3;
    }

    print(m1, 3);
    rotate(m1, 3, 3);
    printf("rotate by 90\n");
    print(m1, 3);
}
