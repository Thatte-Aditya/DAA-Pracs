#include <stdio.h>

int M = 30, sum;
int num[6]={5,10,12,13,15,18};
int sol[6]={0,0,0,0,0,0};

void sumOfSubsets(int i)
{
    if (sum == M) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (sol[j] == 1) 
            {
                printf("%d ", num[j]);
            }
        }
        printf("\n");
    } 
    else if (feas(i)) 
    {
        sol[i] = 1;
        sum += num[i];
        sumOfSubsets(i + 1);
        sol[i] = 0;
        sum -= num[i];
        sumOfSubsets(i + 1);
    }
}

int feas(int i) 
{
    if (sum > M) 
    {
        return 0;
    }
    if (i == 6 && sum < M) 
    {
        return 0;
    }
    return 1;
}

void main()
{
    int len = 0;
    printf("Sum of Subsets Problem using Backtracking\nThe possible options are: \n");
    sumOfSubsets(len);
}