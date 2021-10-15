// WEEK 6
// Lecture 8, 'All Sorts of Sorting'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

void swap(int *, int *);
void printArr(int[], int);
int inOrder(int[], int);
void shuffleArray(int[], int);

int insertionSort(int[], int);

int mergeSort(int[], int, int);

int partition(int[], int, int);
void quickSort(int[], int, int);

void countSort(int[], int);

int main()
{
    // volume of numbers to be sorted
    int size = 1000000;
    // declare array of specified size, and fill it with elements in order 1 .. size
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = i + 1;

    // i want to count time
    clock_t clk;

    // sort algorithms *****************

    printf("Running tests at %d elements.\n", size);

    /*  not gonna bother running the n^2 one for large datasets
    shuffleArray(a, size);
    clk = clock();
    insertionSort(a, size); // insertion sort
    clk = clock() - clk;
    printf("Insertion Sort... ");
    if (inOrder(a, size))
        printf("Pass.\n");
    else
        printf("Fail.\n");
    printf("Took %.3lfms.\n", ((double) clk) / CLOCKS_PER_SEC * 1000);
*/
    shuffleArray(a, size);
    clk = clock();
    mergeSort(a, 0, size - 1); // merge sort
    clk = clock() - clk;
    printf("Merge Sort... ");
    if (inOrder(a, size))
        printf("Pass.\n");
    else
        printf("Fail.\n");
    printf("Took %.3lfms.\n", ((double)clk) / CLOCKS_PER_SEC * 1000);

    shuffleArray(a, size);
    clk = clock();
    quickSort(a, 0, size - 1); // quick sort
    clk = clock() - clk;
    printf("Quick Sort... ");
    if (inOrder(a, size))
        printf("Pass.\n");
    else
        printf("Fail.\n");
    printf("Took %.3lfms.\n", ((double)clk) / CLOCKS_PER_SEC * 1000);

    shuffleArray(a, size);
    clk = clock();
    countSort(a, size); // count sort
    clk = clock() - clk;
    printf("Count Sort... ");
    if (inOrder(a, size))
        printf("Pass.\n");
    else
        printf("Fail.\n");
    printf("Took %.3lfms.\n", ((double)clk) / CLOCKS_PER_SEC * 1000);

    return 0;
}


void printArr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[n - 1]);
}
int inOrder(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}
void shuffleArray(int a[], int size)
{
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < size; i++)
        swap(a + i, a + (rand() % size));
}

/**
 * Insertion Sort:
 * Traverse list to be sorted from left to right
 * Put each element in the correct order relative to all the preceding elements
 * 
 * O(n^2) complexity
 * Worst-case is when algorithm is in reverse sorted order
 * Worst-case comparisons is n(n-1)/2 comparisons, so n^2 complexity
 */
int insertionSort(int a[], int n)
{
    // length must be >=2
    if (n < 2)
        return 0;
    for (int i = 1; i < n; i++) // start at second element, up to top
    {
        int temp = a[i];                 // store starting element
        int j = i;                       // work from current element backwards to start
        while (j > 0 && a[j - 1] > temp) // if previous element is greater than temp, continue to shuffle backwards
        {
            a[j] = a[j - 1]; // shuffle elements forward into blank space, held by temp
            j--;             // move back until reaching correct location
        }
        a[j] = temp; // store temp in its sorted pos'n
    }
    return 1; // return successful sort
}

/**
 * Merge Sort
 * Based on divide-and-conquer strategy
 *  Divide sequence into almost equal halves
 *  Merge-sort each half
 *  Conquer by merging the 2 sorted halves into one sorted sequence
 *  Each sub-list must also be sorted
 * 
 * Runs in O(nlogn) time
 * 
 */
int mergeSort(int a[], int lp, int rp)
{
    int len = rp - lp + 1; // length to be merged, +1 since lp and rp are inclusive
    if (len <= 2)          // base case
    {
        // base case will either be 1 or 2 elements
        // if 2 elements, sort 2 and then return, else just return
        if (len == 2 && a[lp] > a[rp])
            swap(a + lp, a + rp);

        return 1;
    }
    // if not base case, split list, sort splits, then merge sorted splits
    int mid = (lp + rp) / 2;
    mergeSort(a, lp, mid);
    mergeSort(a, mid + 1, rp);
    int r = mid + 1;
    int l = lp;
    int b[len]; // temp array to store merged items
    for (int i = 0; i < len; i++)
    {
        // note: since len prevents the loop from running over, then l and r cannot be out of bounds at the same time
        if ((a[l] < a[r] && l <= mid) || r > rp) // if left is smaller or if r is out of bounds, and l is in bounds
            b[i] = a[l++];                       // merge left
        else                                     // if l is out of bounds, this runs. If r is out of bounds, the above runs.
            b[i] = a[r++];                       // merge right
    }
    // since sorted array is in temp memory, we need to copy sorted elements into original array for return
    for (int i = 0; i < len; i++)
        a[i + lp] = b[i]; // copy sorted array to output
    return 1;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr + i + 1, arr + high);
    return (i + 1);
}
/**
 * QuickSort
 * Outputs sorted list L[p..q], p and q inclusive bounds
 * Uses partitioning
 *  create 2 sub-lists, so every element in list 1 is <= every element in l2
 *  This is chosen based on a pivot, l, which is the first element in the original list
 * recursively partition lists until list is sorted
 * p and q are edges of the current partition, inclusive
 * QuickSort uses two functions: quickSort, and partition
 * 
 * Executes in O(nlogn) time
 */
void quickSort(int L[], int p, int q)
{
    if (p < q)
    {
        int r = partition(L, p, q);
        quickSort(L, p, r - 1);
        quickSort(L, r + 1, q);
    }
    else
        return;
}

/**
 * THERE ARE A FEW LINEAR TIME SORTING ALGORITHMS
 * Counting Sort -> the only one covered in class
 * Bucket Sort
 * Radix Sort
 */

/**
 * Counting sort is a sorting technique based on keys between a specific range. 
 * It works by counting the number of objects having distinct key values (kind of hashing). 
 * Then doing some arithmetic to calculate the position of each object in the output sequence.
 * 
 * complexity O(n+k)    -> n is length of elements, k is volume of keys/values
 * 
 * A key is a value, can occur more than once
 * ex: {1, 2, 2, 3} has n=4, k=3
 * 
 * NOTE: THIS IMPLEMENTATION RELIES ON >=0 VALUES
 */
void countSort(int a[], int n)
{
    // find largest value in array, b (key arr) will have largest + 1 elements
    int largest = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > largest)
            largest = a[i];

    // declare one integer for storing number of keys from 0 .. largest
    int *b = calloc(largest + 1, sizeof(int));

    // count keys
    for (int i = 0; i < n; i++)
        b[a[i]]++;

    // create hash
    /**
     * hash contains index of starting point for each key in output
     * hash is a map of where each value goes in output
     * we can create a hash in place where the counts sit
     */
    for (int i = 1; i < largest + 1; i++)
        b[i] += b[i - 1];

    // create a second array, for output
    int *out = calloc(n, sizeof(int));

    // sort array
    /**
     * each element looks up its key iterator location in the hash, and stores there
     * b stores how many of each key have been used so far, so increment iterator by b[key] for each key that is used
     */
    for (int i = 0; i < n; i++)
        out[b[a[i]]++] = a[i];

    // copy sorted array into original
    for (int i = 0; i < n; i++)
        a[i] = out[i];

    // free memory from sort
    free(b);
    free(out);
}