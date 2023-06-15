#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int count = 0, c, i, j, n, w = 0;
    int weight[MAX], used[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the capacity of container: ");
    scanf("%d", &c);

    printf("\nEnter the weight of each item: ");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    for (i = 0; i < n - 1 ; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (weight[j] > weight[j + 1])
            {
                int temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        printf("%d ",weight[i]);
    printf("\n");
    for(i = 0; i < n; i++)
    {
        if(weight[i] <= c)
        {
            count++;
            used[i] = 1;
            c -= weight[i];
        }
    }

    printf("The number of containers loaded is: %d\n", count);
    return 0;
}