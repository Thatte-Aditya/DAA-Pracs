// Greedy - Kruskal's Algorithm
#include <stdio.h>

int a, b, i, j, k, v, y, z, ne = 1;
int min, minimumCost = 0;
int cost[10][10], parent[10];

int find(int i)
{
    while (parent[i])     
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void main()
{
    printf("Minimum Spanning Tree using Kruskal's Algorithm\nEnter the no. of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)         
                cost[i][j] = 999;
        }
    }
    printf("\nThe edges of the equivalent Minimum Spanning Tree are\n");
    while (ne < v)
    {
        for (i = 1, min = 999; i <= v; i++)
        {
            for (j = 1; j <= v; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = y = i;
                    b = z = j;
                }
            }
        }
        y = find(y);
        z = find(z);
        if (uni(y, z))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            minimumCost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", minimumCost);
}