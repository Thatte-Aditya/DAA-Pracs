// Optimal Storage on Tapes
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int  c, count = 0, i, j, n;
    float mrt, sum = 0;
    int size[MAX],id[MAX],used[MAX];

    printf("Enter the number of files: ");
    scanf("%d", &n);

    printf("Enter the id of files: ");
    for (i = 0; i < n; i++)
        scanf("%d",&id[i]);
    printf("Enter the size of files: ");
    for (i = 0; i < n; i++)
        scanf("%d",&size[i]);
    printf("\nBefore Sorting: ");
    for(i = 0; i < n; i++)
    {
        printf("File %d - %dMB ",id[i],size[i]);
        printf("\n");
    }

    for (i = 0; i < n - 1 ; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (size[j] > size[j+1])
            {
                int temp = size[j];
                size[j] = size[j + 1];
                size[j + 1] = temp;

                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }
    printf("\n\n");
    for(i = 0; i < n; i++)
    {
        printf("File %d - %dMB ",id[i],size[i]);
        printf("\n");
    }
    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        int sum1 = 0;
        for (j = 0; j <= i; j++)
        {
            sum1 += size[j];
        }
        sum += sum1;
        mrt = sum / n;
        printf("%f \n", sum);  
    }
    printf("Order of storage on tapes:\n");
    for(i = 0; i < n; i++)
        printf("%d ", id[i]);
    printf("\n");
    printf("The optimal MRT is: %.2f\n", mrt);
    return 0;
}