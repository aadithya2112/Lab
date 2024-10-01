#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int *m1, int *m2, int *result, int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1 * c2; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i * c2 + j] += m1[i * c1 + k] * m2[k * c2 + j];
            }
        }
    }
}

int *makematrix(int rows, int cols)
{
    int *m = (int *)malloc(rows * cols * sizeof(int));
    if (m == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return m;
}

int main()
{
    int r1, c1, r2, c2;

    printf("enter no of rows and columns for the 1st matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("enter no of rows and columns for the 2nd matrix: ");
    scanf("%d %d", &r2, &c2);

    int *m1 = makematrix(r1, c1);
    int *m2 = makematrix(r2, c2);
    int *result = makematrix(r1, c2);

    if (c1 != r2)
    {
        printf("matrix multiplication is not possible.\n");
        free(m1);
        free(m2);
        free(result);
        return 1;
    }

    printf("enter elements of the 1st matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m1[i * c1 + j]);
        }
    }

    printf("enter elements of the 2nd matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m2[i * c2 + j]);
        }
    }

    multiplyMatrices(m1, m2, result, r1, c1, r2, c2);

    printf("result of matrix multiplication:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i * c2 + j]);
        }
        printf("\n");
    }

    free(m1);
    free(m2);
    free(result);

    return 0;
}

// Algorithm
// 1. Initialize Result Matrix:

// 1.1  For i from 0 to r1-1:
// 1.2 For j from 0 to c2-1:
// 1.3 Set result[i * c2 + j] to 0.
// 1.4 Matrix Multiplication:

// 2.1 For each i from 0 to r1-1:
// 2.2 ⁠For each j from 0 to c2-1:
// 2.3 For each k from 0 to c1-1:
// 2.4 Calculate result[i * c2 + j] += m1[i * c1 + k] * m2[k * c2 + j].

// 3.  Input and Memory Management:

// 3.1 Read dimensions r1, c1, r2, c2.
// 3.2 Allocate memory for m1, m2, result.
// 3.3 If c1 != r2, print error and exit.
// 3.4 Read elements of m1 and m2.
// 3.5 Print elements of result.
// 3.6 Free allocated memory for m1, m2, result.