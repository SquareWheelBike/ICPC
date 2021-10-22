#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int main(void)
{
    // if any of the digits in the current line are 7, then output is yes
    int t; // number of test cases
    scanf("%d", &t);
    // i for 3 count, n for input buffer (char for faster read)
    // int i;
    int me, you, k, moves;

    for (int c = 0; c < t; ++c)
    {
        scanf("%d %d", &me, &you);
        moves = 0;
        int diff = you - me;
        // case 1: I need to move backwards
        if (diff < 0)
        {
            moves += abs(diff);
        }
        // case 2: I need to move forwards
        else
        {
            moves += abs(diff) / 2;
            if (diff % 2 == 1)
            {
                moves += 2;
            }
        }
        printf("%d\n", moves);
    }
    exit(0);
}