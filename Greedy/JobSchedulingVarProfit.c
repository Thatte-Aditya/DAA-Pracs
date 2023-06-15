#include <stdio.h>
#define max 4

void main()
{
    int i, j, k, temp;
    int end = 0, job[max][3], outputArr[20] = {0};
    printf("\nJob Scheduling Algorithm for variable profit");
    for (i = 0; i < max; i++)
    {
        job[i][0] = i + 1;
        printf("\nJob ID : %d\nEnter the end time: ",i + 1);
        scanf("%d", &job[i][1]);
        printf("Enter the profit: ");
        scanf("%d", &job[i][2]);
    }
    //Sorting the jobs on the basis of their profits in the descending order
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max - 1; j++)
        {
            if (job[j][2] < job[j + 1][2])
            {
                for (k = 0; k < 3; k++)
                {
                    temp = job[j][k];
                    job[j][k] = job[j + 1][k];
                    job[j + 1][k] = temp;
                }
            }
        }
    }
    for (i = 0; i < max; i++)
    {
        printf("\n%d \t%d \t%d", job[i][0], job[i][1], job[i][2]);
    }
    for (i = 0; i < max; i++) 
    {
        if(job[i][1] > end)
            end = job[i][1];
    }
    printf("\nMax endtime = %d",end);
    for (i = 0; i < max; i++) 
    {
        if(outputArr[job[i][1]] == 0)
            outputArr[job[i][1]] = job[i][0];
        else if(outputArr[job[i][1]] != 0)
        {
            k = job[i][1];
            while(outputArr[k] != 0)
            {
                k--;
            }
            outputArr[k] = job[i][0];
        }
    }
    printf("\nResultant Array is: ");
    for (i = 0; i <= end; i++) 
    {
        printf("%d  ",outputArr[i]);
    }
}