#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
// #include <string.h>

#include <math.h>

// this should work fine
int prime[100000];	// prime number hash map
					// prime[i] = 1 means i is prime
					// prime[i] = 0 means i is not prime

int primeList[10000];	// array containing only prime numbers
int pl_len;				// length of primelist

void SieveOfEratosthenes(int n = 100000) {

	int p, j;

	// set all elements of prime[] to 1
	for (j = 0; j < n; ++j)
		prime[j] = 1;

	prime[1] = 0; // 1 is not prime
	for (p = 2; p <= sqrt(n); ++p) {
		for (j = p * p; j < n; j += p) {
			prime[j] = 0;
		}
	}

	// creating list of prime numbers
	pl_len = 0;
	for (p = 2; p < n; ++p) {
		if (prime[p] == 1)
			primeList[pl_len++] = p;
	}

}

int smallest_divisor(int n) {

	int i = 0;
	// iterating prime numbers less than square root of N
	while (primeList[i] <= sqrt(n)) {
		if (n % primeList[i] == 0)
			return primeList[i];
		++i;
	}
	return n;
}

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
    SieveOfEratosthenes();  // create prime hashmap

    int t; // number of test cases
    scanf("%d", &t);

    for (int c = 0; c < t; ++c)
    {
        int x, k;
        scanf("%d %d", &x, &k);

        // find sm and lg lcm(i,j) for combinations of x <= i < j <= x*k
        int xk = k * x; // use x, k for i,j bounds

        int lg = lcm(xk, xk - 1);

        // start by finding sm
        int sm = MIN(x * 2, x * smallest_divisor(x));

        printf("%d %d\n", sm, lg);
    }
    exit(0);
}