#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int gcd(int m, int n)
{
    int r = m % n;
    if (!r)
        return n;
    return gcd(n, r);
}

int lcm(int j, int k)
{
    return j * k / gcd(j, k);
}

int main(void)
{
    int t; // number of test cases
    scanf("%d", &t);

    for (int c = 0; c < t; ++c)
    {
        int x, k;
        scanf("%d %d", &x, &k);

        // find min and max lcm(i,j) for combinations of x <= i < j <= x*k
        int xk = k * x; // use x, k for i,j bounds

        int min = k, max = lcm(xk, xk - 1);
        
        // start by finding min
        for (int i = x; i < i * 2; i++) // brute force method
        {
            for (int j = i + 1; j <= i * 2; j++)
            {
                int tmp = lcm(i, j);
                if (min > tmp)
                    min = tmp;
                //if (max < tmp)
                //    max = tmp;
            }
        }

        printf("%d %d\n", min, max);
    }
    exit(0);
}