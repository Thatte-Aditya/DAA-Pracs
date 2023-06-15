#include <stdio.h>
#define size 5
int prev[size];
int leastedge[size];
int included[size];

int least(int n)
{
    int min = 100, minvertex;
    for (int j = 1; j < n; j++)
    {
        if (included[j] == 0 && leastedge[j]<min)
            min = leastedge[j], minvertex = j;
    }
    return minvertex;
}

void main()
{
    // //int adjmat[5][5] = {{ 0, 1, 0, 2, 0 },
    //     { 1, 0, 7, 12, 5 },
    //     { 0, 7, 0, 0, 4 },
    //     { 2, 12, 0, 0, 3 },
    //     { 0, 5, 4, 3, 0 }
    // //};
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int adjmat[n][n];
    printf("Enter adjoint matrix for vertexes:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &adjmat[i][j]);

    for (int i = 0; i < n; i++)
        leastedge[i] = 100, included[i] = 0;

    leastedge[0] = 0;
    prev[0] = -1;
    for (int i = 0; i < n-1; i++)
    {
        int u = least(n);
        included[u] = 1;
        for (int v = 0; v < n; v++)
            if (adjmat[u][v] && included[v] == 0 && adjmat[u][v] < leastedge[v])
                prev[v] = u, leastedge[v] = adjmat[u][v];
    }
    printf("Edges included in mst will be:\n");
    for (int i = 1; i < n; i++)
        printf("%d,%d\t", prev[i]+1, i+1);
}