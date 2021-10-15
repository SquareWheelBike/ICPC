// chefs and operations

/**
 * t test cases
 * n integers in sets A and B
 *  
 */

// gcc qabc.c -Wall && ./a.out < input.txt

#define SIZE 100000

#include <stdio.h>
// #include <stdlib.h>

int checkSequence(int[], int[], int);

int main(void)
{
    int t, n, A[SIZE], B[SIZE], c, i;
    // get total number of test cases
    scanf(" %d", &t);

    for (c = 0; c < t; ++c)
    {
        scanf(" %d", &n);
        // get array A
        for (i = 0; i < n; i++)
        {
            scanf(" %d", A + i);
        }
        // get array B
        for (i = 0; i < n; i++)
        {
            scanf(" %d", B + i);
        }
        if (checkSequence(A, B, n) == 1)
        {
            puts("TAK");
        }
        else
        {
            puts("NIE");
        }
    }
    return 0;
}

int checkSequence(int A[], int B[], int n)
{
    int cutoff = n - 2; // faster to cache cutoff point
    int i, j;
    for (i = 0; i < cutoff; ++i)
    {
        if (A[i] > B[i])
        {
            return 0;
        }
        if (A[i] < B[i])
        {
            int coeff = B[i] - A[i];
            // apply incrementation pattern to next 3 numbers
            for (j = 0; j < 3; j++)
            {
                A[i + j] += (j + 1) * coeff;
            }
        }
    }
    // check last 2 locations
    for (; cutoff < n; ++cutoff)
    {
        if (A[cutoff] != B[cutoff])
        {
            return 0;
        }
    }
    return 1;
}