// DP - Longest Common Subsequence
#include <stdio.h>
#include <string.h>

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20], result[10];

int main()
{
    printf("Longest Common Subsequence problem using Greedy approach: \n");
    printf("Enter 1st sequence: ");
    scanf("%s", x);
    printf("Enter 2nd sequence: ");
    scanf("%s", y);
    m = strlen(x);
    n = strlen(y);
    for (i = 0; i <= m; i++)
    {
        c[i][0] = 0;
        b[i][0] = 'n';
    }
    for (i = 0; i <= n; i++)
    {
        c[0][i] = 0;
        b[0][i] = 'n';
    }
    // d, l and u denotes diagonal, left and up directions respectively // n denotes null
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
    printf("\nInteger 2D Array is as follows\n");
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("\nCharacter 2D Array is as follows\n");
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%c\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Longest Common Subsequence is ");
    int min = m < n ? m : n;
    result[min];
    int k = 0;
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == 'd')
        {
            result[k] = x[i - 1];
            k++;
            i--;
            j--;
        }
        else if (b[i][j] == 'u')
            i--;
        else
            j--;
    }
    for(k = min; k >= 0; k--)
        printf("%c",result[k]);
    return 0;
}