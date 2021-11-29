// longest increasing subsequence

#define MAX 400
int data[MAX][MAX];
int length[MAX];
#include <vector>
#include <stdio.h>
/* length [i] is the length of the maximal increasing
sub sequence of x[0] ... x[n-1] that involves x [ i ] as its last element .
data[i][0] ... data[i][length[i]-1] is the sequence of
members of that maximal sub sequence ( so the last element is i ).
*/
class Sequences
{
public:
    /* if there are several answers o f maximum length, return one whose
       last element is as small as possible */
    std::vector<int> LongestIncreasing(std::vector<int> &x)
    {
        int n = x.size();
        length[0] = 0;
        length[1] = 1;
        int i, j, k;
        data[0][0] = 0;
        length[0] = 1;
        for (i = 1; i < n; i++)
        {
            int max1 = 0;
            // Find the max length of increasing sub sequences of x[0] ... x [i-1] ending
            // in values < x[i] 
            int index1 = -1;
            for (j = 0; j < i; j++)
            {
                if (x[j] < x[i])
                {
                    if (max1 < length[j] && x[j] < x[i])
                    {
                        max1 = length[j];
                        index1 = j;
                    }
                }
            }
            if (index1 == -1)
            {
                length[i] = 1;
                data[i][0] = x[i];
            }
            else
            {
                length[i] = max1 + 1;
                for (k = 0; k < max1; k++)
                {
                    data[i][k] = data[index1][k];
                }
                data[i][max1] = i;
            }
        }
        // Now data is complete
        int max = 0;
        int index = -1;
        for (i = 0; i < n; i++)
        {
            if(length[i] > max)
            {
                max = length[i];
                index = i;
            }
        }
        std::vector<int> ans;
        for (j = 0; j < length[index]; j++)
        {
            ans.push_back(data[index][j]);
        }
        return ans;
    }
};

int input[] = {5, 1, 6, 7, 3, 4, 5};

int main()
{
    Sequences z;
    std::vector<int> x;
    int i, j;
    for (i = 0; i < sizeof(input) / sizeof(int); i++)
        x.push_back(input[i]);
    std::vector<int> ans;
    ans = z.LongestIncreasing(x);
    int n = x.size();
    printf("\nInput: ");
    for (i = 0; i < n; i++)
        printf("%d", x[i]);
    for (i = 0; i < n; i++)
    {
        printf("\nending at[%d] = %d", i, x[data[i][0]]);
        for (j = 1; j < length[i]; j++)
            printf(", %d", x[data[i][j]]);
    }
    printf("\n answer is { ");
    int m = ans.size();
    for (i = 0; i < m; i++)
        printf("%d ", x[ans[i]]);
    printf("}\n");
    return 0;
}
