// this is the first preliminary qualifier round
// problem code: QUALPREL

// Submission by Cole Fuerth, at University of Windsor

// PROBLEM:
/**\
 * two rounds, A and B
 * in each round, teams are sorted in descending order by their score
 * Each team with score >=K=1500 place advances to the pre-elimination round (meaning, if there are teams tied with k=1500th place, there are more than 1500 teams)
 * 
 * input:
 * first line contains T, the number of test cases
 * first line of each test case contains two integers, space-separated, N and K
 * second line of each test case contains N space separated characters, S1, S2, ..., Sn
 * 
 * output: for each test case, print a single line containing one integer: the number of qualified teams
 */

// ASSUME INPUT IS ON STDIN AND OUTPUT ON STDOUT

// picked C for speed

// gcc-6 qualprel.c -Wall -o q && /usr/bin/time -v ./q < biginput.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void timSort(int[], int);
void merge(int[], int, int, int);
void insertionSort(int[], int, int);
int min(int, int);
const int RUN = 32;

int main(void)
{
    // input on stdin
    // need number of test cases
    int t, n, k; // number of test cases, number of entries in current case, pivot point

    // each value can be as big as 10^9, but integers can store up to 2.147*10^9, so we are good
    int *s = NULL; // s will store each value in line

    // need number of test cases before starting
    scanf("%d", &t);

    int passing, pivot, j;
    // loop through each test case
    for (int c = 0; c < t; ++c)
    {
        // two space-separated integers on next line
        scanf("%d %d", &n, &k); // get n and k
        s = realloc(s, n * sizeof(int));
        // fill s with input
        // now that line is in memory, we can quickly traverse it to get our list of integers for current test case
        for (int i = 0; i < n; ++i)
        {
            scanf(" %d", s + i);
            // printf(" %d", *(s+i));
        }
        // timsort is the python sorting algorithm; has some small efficiencies that I can take advantage of
        timSort(s, n);
        // now, from k space, find how many more teams are added to passing set
        // since quicksort is in ascending order, we will look at array in reverse
        j = n - k;    // location of kth entry; k=1 will select final entry; k=n will select first (smallest) entry
        passing = k;  // we know there are at least k passing teams
        pivot = s[j]; // faster to store pivot
        --j;          // need to decrement j so it points to next spot to compare to
        // count number of additional passing grades
        while (j >= 0 && s[j] == pivot)
        {
            ++passing;
            --j;
        }
        // print number of passing grades to stdout
        printf("%d\n", passing);
    }
    // printf("total time %ld\nmem time %ld\nio time %ld\nsort time %ld\nunaccounted time %ld\n", t_whole, t_mem_sum, t_io_sum, t_sort_sum, t_whole - (t_mem_sum + t_io_sum + t_sort_sum));
    // free associated memory
    free(s);
    exit(0);
}

int min(int a, int b)
{
    return !(b < a) ? a : b;
}

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{

    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void timSort(int arr[], int n)
{

    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n;
         size = 2 * size)
    {

        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}