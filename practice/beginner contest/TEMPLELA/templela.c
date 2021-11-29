// this is the first preliminary qualifier round
// problem code: QUALPREL

// Submission by Cole Fuerth, at University of Windsor

// PROBLEM:
/**\
 * i strips of land
 * strips are N[i] length, and each N[i] has an associated array of heights, H[1] .. H[N[i]], in sequential order
 *  - each strip is divided into N[i] parts, each part with an array of heights
 * strip is valid if these conditions are met:
 *  - has a unique 'center' part, meaning there are an equal number of parts on the left and right of this part
 *  - H[i][1] = 1 (first height in each strip is 1)
 *  - heights increase by exactly 1, as you move from left to center
 *  - heights decrease by 1 going from center to right
 * 
 * input structure:
 * first line is single integer, number of strips
 * each strip has a single int on its own line, N length of strip
 * next line is N integers, check that they form a pyramid
 * 
 * constraints:
 * 1 <= S <= 100
 * 3 <= N <= 100
 * 1 <= H[i] <= 100
 * 
 * output:
 * 'yes' or 'no' on stdout for result
 */

// ASSUME INPUT IS ON STDIN AND OUTPUT ON STDOUT

// picked C for speed

// gcc-6 templela.c -Wall -o t && /usr/bin/time -v ./t < input.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkLine();

int S, N, *H = NULL; // number of strips, number of entries in current case, array for heights

int main(void)
{
    // need number of test cases before starting
    scanf("%d", &S);

    // loop through each test case
    for (int c = 0; c < S; c++)
    {
        if (checkLine())
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    // free associated memory
    free(H);
    exit(0);
}

int checkLine()
{
    // READ STRIP FROM STDIN
    // two space-separated integers on next line
    scanf(" %d", &N); // get N value
    H = realloc(H, N * sizeof(int));

    // read H array, MUST do this every time to clear line from stdin
    for (int i = 0; i < N; ++i)
    {
        scanf(" %d", H + i);
    }

    // CHECKS ON SET
    // if set is even size, or smaller than minimum size, then not ok
    if (N % 2 == 0 || N < 3)
        return 0;
    // faster to make a reference
    const int mid = N / 2;
    // if first and last values are not 1, then return
    if (H[0] != 1 || H[N-1] != 1 || H[mid] - H[mid-1] != 1)
        return 0;
    // get center value
    for (int i=1; i<mid; i++)
    {
        if (H[i] != H[N-i-1])
            return 0;
        if (H[i] - H[i-1] != 1)
            return 0;
    }
    return 1;
}
