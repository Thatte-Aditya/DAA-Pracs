//Dynamic Programming - Coin Changing Algorithm
#include <stdio.h>

int min(int y, int z)
{
    if (y < z)
    {
        return y;
    }
    else
    {
        return z;
    }
}

int main()
{
    int amount, i, j, n;
    printf("Enter the number of denominations: ");
    scanf("%d", &n);
    printf("Enter the amount: ");
    scanf("%d", &amount);
    int deno[n];
    printf("Enter the denominations:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &deno[i]);
    }
    // Sort
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (deno[i] > deno[j])
            {
                int temp = deno[i];
                deno[i] = deno[j];
                deno[j] = temp;
            }
        }
    }
    int ans[n][amount + 1];
    for (i = 0; i <= amount; i++)
    {
        ans[0][i] = i;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j <= amount; j++)
        {
            if (j < deno[i])
            {
                ans[i][j] = ans[i - 1][j];
            }
            else
            {
                ans[i][j] = min(ans[i][j - deno[i]] + 1, ans[i - 1][j]);
            }
        }
    }
    printf("\nDenomination\n");
    for (i = 0; i <= amount; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", deno[i]);
        for (j = 0; j <= amount; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }
    int solutionArray[n];
    for (i = 0; i < n; i++)
    {
        solutionArray[i] = 0;
    }
    int row = n - 1;
    while (amount > 0 && row >= 0)
    {
        if (deno[row] <= amount && ans[row][amount] - ans[row][amount - deno[row]] == 1)
        {
            solutionArray[row]++;
            amount -= deno[row];
        }
        else
        {
            row--;
        }
    }
    printf("\nNo of coins needed:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d: %d\n", deno[i], solutionArray[i]);
    }
    return 0;
}