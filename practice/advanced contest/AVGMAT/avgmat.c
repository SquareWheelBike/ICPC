
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * each test case is a grid n*m, each cell is either empty or contains a house
 * distance between houses is the manhattan distance between the cells containing them
 * for each d between 1 and (N + M - 2) inclusive, chef wants to calculate the number of unordered pairs of distinct houses with distance equal to d
 * 
 * @return int 
 */

int abs(int x){
    return (x < 0) ? -x : x;
}

int manhattandistance(int a[], int b[]){
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main(void)
{

    int t; // number of test cases
    scanf("%d", &t);

    for (int c = 0; c < t; c++)
    {
        // each case has two integers up front: n, m
        int n, m;
        scanf("%d %d", &n, &m);
        int cells[n * m][2]; // coordinate sets
        // memset(cells, 0, n * m); // 0 out the cells
        int numcells = 0;

        // n is the number of lines that follow. Injest these lines:
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int temp;
                scanf("%1d", &temp);
                if (temp == 1)
                {
                    cells[numcells][0] = i;
                    cells[numcells][1] = j;
                    ++numcells;
                }
            }
        int distmax = n + m - 2;
        int distances[distmax];
        memset(distances, 0, sizeof(distances));
        for (int i=0; i<numcells; i++){
            for (int j=i+1; j<numcells; j++){
                ++distances[manhattandistance(cells[i], cells[j]) - 1];
            }
        }
        for (int i=0; i<distmax; i++){
            printf("%d ", distances[i]);
        }
        printf("\n");
    }
    exit(0);
}