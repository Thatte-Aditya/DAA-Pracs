//Greedy - Fractional Knapsack
#include <stdio.h>
#define max 10

float p[max], pw[max], w[max], temp;

void main()
{
    int i, j, n, knapsack = 0;
    printf("Greedy Technique - Fractional Knapsack Problem");
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the profit and weight of the elements: ");
    for(i = 0; i < n; i++)
    {
        printf("\nElement %d: \nProfit = ",i + 1);
        scanf("%f",&p[i]);
        printf("Weight = ");
        scanf("%f",&w[i]);
        pw[i] = p[i]/w[i];
    }
    printf("\nBefore Swapping: \n");
    for(i = 0; i < n; i++)
        printf("%.2f\t",pw[i]);
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pw[i] < pw[j])
            {
                temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
    printf("\nAfter Swapping: \n");
    for(i = 0; i < n; i++)
        printf("%.2f\t",pw[i]);
    i = 0;
    float profit = 0.0;
    printf("\nEnter the capacity of knapsack: ");
    scanf("%d",&knapsack);
    while(knapsack != 0)
    {
        if(knapsack < w[i])
        {
            profit += knapsack * pw[i];
            knapsack = 0;
        }
        else
        {
            profit += p[i];
            knapsack -= w[i];
        }
        i++;
    }
    printf("\nTotal Profit = %.2f",profit);
}