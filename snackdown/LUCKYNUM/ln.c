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
    char n, chars, flag; // temps

    for (int c=0; c<t; ++c){
        flag = 0;
        chars = 0;
        while (chars < 3){
            // since each number is a single character, we can inject the three space separated integers with getchar()
            n = getchar();
            if (n >= '0' && n <= '9')
            {
                ++chars;
                if (n == '7')
                    flag = 1;
            }
        }
        if (flag == 1)
            puts("YES");
        else
            puts("NO");
    }
}