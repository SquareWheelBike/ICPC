#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define FOR(c, m) for (int c = 0; c < (m); c++)

/**
 * Today, Chef took a big chessboard with N rows (numbered 1 through N) and N columns (numbered 1 through N). Let's denote the square in row  * r and column c of the chessboard by (r,c). Chef wants to place some queens on this chessboard in such a way that the following conditions  are satisfied:
 * 
 * Each square of the board contains at most one queen.
 * There are exactly N−2 queens on the board
 * All squares are reachable by at least one queen.
 * 
 * A queen can reach all cells along the row, column, and diagonals it is placed at.
 * 
 * Formally, a queen placed at square (r,c) can reach square (x,y) if at least one of the following conditions holds:
 * x=r
 * y=c
 * r+c=x+y
 * r−c=x−y
 */
int main(void)
{
    int t; // number of test cases
    scanf("%d", &t);

    // loop through test cases
    FOR(0, t){
        
    }
}