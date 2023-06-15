// DP - Matrix Chain Multiplication
#include <stdio.h>

void main()
{
    printf("Matrix Chain Multiplication using Dynamic Programming");
    int i, j = 0, k, l, minCost, n, temp1, temp2;
    printf("\nEnter the number of matrices: ");
    scanf("%d", &n);
    int cost[n + 1][n + 1], path[n][n], order[n + 1];
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the order of matrix %d: ", i + 1);
        if(i == 0)
            scanf("%d %d", &order[j],  &order[j + 1]);
        else
        {
            scanf("%d %d", &temp1, &temp2);
            if(temp1 == order[j])
            {
                order[j] = temp1;
                order[j + 1] = temp2;
            }
            else
            {
                printf("Matrix Chain Multiplication is not possible");
                break;
            }
        }
        j++;
    }
    printf("\n\nArray of Orders of the Matrices is: ");
    for(i = 0; i <= n; i++)
        printf("%d\t", order[i]);
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if (j == i + 1)
                cost[i][j] = 0;
            else
                cost[i][j] = 99999;
        }
    }
    for(l = 2; l <= n; l++)
    {
        for(i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;
            cost[i][j + 1] = 99999;
            for(k = i; k < j; k++)
            {
                minCost = cost[i][k + 1] + cost[k + 1][j + 1] + (order[i] * order[k + 1] * order[j + 1]);
                if(minCost < cost[i][j + 1])
                {
                    cost[i][j + 1] = minCost;
                    path[i][j] = k;
                }
            }
        }
    }
    printf("\nFinal Matrix is as follows\n");
    for(i = 0; i < n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d\t", cost[i][j]);
        printf("\n");
    }
    printf("\n\nMinimum number of multiplications is: %d", cost[0][n]);
}