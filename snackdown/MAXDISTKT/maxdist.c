// maxiumum number of distinct elements
// normal integers are large enough to handle this test

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define ARRMAX 200000 // max N size

int main(void)
{
    // if any of the digits in the current line are 7, then output is yes
    int t; // number of test cases
    scanf("%d", &t);

    // declare memory for arrays, just jump right to max size
    int A[ARRMAX], B[ARRMAX], C[ARRMAX];

    int n; // number of integers in current test case

    for (int c = 0; c < t; ++c)
    {
        scanf("%d", &n);
        // B is input array, A is processed array
        for (int i = 0; i < n; ++i)
        {
            // inject integers in case here
            scanf(" %d", B + i);
        }
        // process sequences here
        // find an array A, such that C[i] = A[i] % B[i], ∀i∈{1,N} has a maximum number of distinct integers
        // I could try adding elements one at a time, with brute force. If C[i] = (0 <= test <= 10^9) % B[i] is unique, then set A[i] to test and move on
    }
    return 0;
}