#include <stdio.h>
#include <stdbool.h>

void printSolution(int color[],int V)
{
    printf("Coloring Solution:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

bool isSafe(int V,int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUntil(int V,bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(V,v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUntil(V,graph, m, color, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int V,bool graph[V][V], int m)
{
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=0;

    if (!graphColoringUntil(V,graph, m, color, 0))
    {
        printf("Solution does not exist");
        return false;
    }
    printSolution(color,V);
    return true;
}

int main()
{
    //0,1,1,1
    //1,0,1,0
    //1,1,0,1
    //1,0,1,0

    int V;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    bool graph[V][V];
    printf("Enter graph matrix:\n");

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            scanf("%d",&graph[i][j]);

    int m = 3;
    graphColoring(V,graph, m);
    return 0;
}