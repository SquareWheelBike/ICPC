// kitchen timetable

// gcc-6 kttable.c -Wall && ./a.out < input.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i, t, n, *stime = NULL, temp, passing; 
    // get total number of test cases
    scanf("%d", &t);

    for (int c = 0; c < t; c++)
    {
        // each test case starts with n, the number of students
        scanf(" %d", &n);

        stime = realloc(stime, sizeof(int) * n);
        passing = 0;    // reset count of passing students

        // get schedule
        for (i=0; i<n; i++)
        {
            scanf(" %d", stime + i);
        }

        // first student is a special case
        scanf(" %d", &temp);
        if (temp <= stime[0])
        {
            passing++;
        }

        for (i=1; i<n; ++i)
        {
            scanf(" %d", &temp);
            if (temp <= stime[i] - stime[i-1])
            {
                passing++;
            }
        }

        // print result
        printf("%d\n", passing);
    }
}
