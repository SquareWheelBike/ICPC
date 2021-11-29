
/**
 * Problem:
 * starts with a total number of snakes
 * each snake comes with a character count
 * dots are whitespace, each 'H' is a head, each 'T' is a tail
 * we need to verify that each snake starts with a head and ends with a tail
 */

// gcc-6 snakproc.c -Wall && /usr/bin/time -v ./a.out < input.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // input comes in on stdin
    int r, l, stack, invalid;
    // char *s = NULL;

    // need number of snakes
    scanf("%d", &r);

    for (int c = 0; c < r; c++)
    {
        // l characters are read in, then use a stack to keep track of start and end of snakes
        scanf(" %d", &l);
        // s = realloc(s, l * sizeof(char));
        stack = 0;
        invalid = 0;    // reset invalid flag
        for (int i=0; i<l; i++)
        {
            switch(getchar())
            {
                case '\n':
                case ' ':
                    --i;
                    break;
                case 'H':
                    ++stack;
                    break;
                case 'T':
                    --stack;
                    break;
            }
            if (stack < 0 || stack > 1)
            {
                invalid = 1;
            }
        }
        if (invalid || stack != 0)
        {
            puts("Invalid");
        }
        else
        {
            puts("Valid");
        }
    }
}
