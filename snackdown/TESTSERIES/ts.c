#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int main(void)
{
    // if any of the digits in the current line are 7, then output is yes
    int t;  // number of test cases
    scanf("%d", &t);
    // i for 3 count, n for input buffer (char for faster read)
    // int i;
    char n, chars, india, england; // temps

    for (int c=0; c<t; ++c){
        chars = 0;
        india = 0;
        england = 0;
        while (chars < 5){
            // since each number is a single character, we can inject the three space separated integers with getchar()
            n = getchar();
            if (n >= '0' && n <= '2')
            {
                ++chars;
                if (n == '1')
                    ++india;
                else if (n == '2')
                    ++england;
            }
        }
        if (india > england)
            puts("INDIA");
        else if (india < england)
            puts("ENGLAND");
        else    
            puts("DRAW");
    }
}