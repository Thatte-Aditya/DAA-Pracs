#include <stdio.h>

#define max 5

void main()
{
    int i, j, k, temp;
    int end = 0, job[max][5],outputArr[20] = {0};
    printf("Greedy Method");
    printf("\nJob Sequencing Algorithm for jobs with equal profit and variable start & end time");
    printf("\nNumber of jobs = %d\n",max);
    for (i = 0; i < max; i++)
    {
        job[i][0] = i + 1;
        printf("\nJob ID : %d\nEnter the start time: ",i + 1);
        scanf("%d", &job[i][1]);
        printf("Enter the end time: ");
        scanf("%d", &job[i][2]);
        job[i][3] = job[i][2] - job[i][1] + 1;
        job[i][4] = 0;
    }
    printf("\n2D Array before sorting: ");
    for (i = 0; i < max; i++)
    {
        printf("\n%d \t%d \t%d \t%d \t%d", job[i][0], job[i][1], job[i][2], job[i][3], job[i][4]);
    }
    //Sorting the jobs on the basis of their (end time - start time) in the ascending order
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max - 1; j++)
        {
            if (job[j][3] > job[j + 1][3])
            {
                for (k = 0; k < 5; k++)
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
        if(job[i][2] > end)
            end = job[i][2]; //setting max end time 
    }
    for (i = 0; i < max; i++) 
    {
        for(j = job[i][1]; j <= job[i][2]; j++)
        {
            if(outputArr[j] != 0)
                job[i][4] = 1;
            else
                continue;
        }
        if(job[i][4] == 0)
        {
            //if all blocks inside output array are free
            for(j = job[i][1]; j <= job[i][2]; j++)
            {
                outputArr[j] = job[i][0]; //assigning id to the output array based on length of the job  
            }
        }
        else
            continue;
    }
    printf("\n\n2D Array after sorting and checking: \n");
    for (i = 0; i < max; i++)
    {
        printf("\n%d \t%d \t%d \t%d \t%d", job[i][0], job[i][1], job[i][2], job[i][3], job[i][4]);
    }
    printf("\n\nResultant Array = ");
    for (i = 0; i <= end; i++) 
    {
        printf("%d  ",outputArr[i]);
    }
}