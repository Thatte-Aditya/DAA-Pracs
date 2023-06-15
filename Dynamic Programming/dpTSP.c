#include <stdio.h>
#include <stdlib.h>

int n = 4; 
int dist[4][4] = {
    {0, 5, 10, 15},
    {6, 0, 8, 12},
    {8, 10, 0, 14},
    {7, 9, 20, 0}
};
int dp[1<<4][4];
int path[1<<4][4];

int tsp(int mask, int pos) {
    if (mask == (1<<n)-1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = 999;
    int next = -1;
    for (int i = 0; i < n; i++) {
        if ((mask&(1<<i)) == 0) { 
            int newans = dist[pos][i] + tsp(mask|(1<<i), i);
            if (newans < ans) {
                ans = newans;
                next = i;
            }
        }
    }
    dp[mask][pos] = ans;
    path[mask][pos] = next;
    return ans;
}

int main() {
    // initialize dynamic programming array to -1
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int cost = tsp(1, 0); // start from the first city (0) and visit all cities (mask = 1)

    // print the minimum cost
    printf("Minimum cost: %d\n", cost);

    // print the minimum cost path
    printf("Minimum cost path: ");
    int mask = 1;
    int pos = 0;
    printf("%d -> ", pos);
    while (mask != (1<<n)-1) {
        int next = path[mask][pos];
        printf("%d -> ", next);
        mask |= (1<<next);
        pos = next;
    }
    printf("0\n");
    return 0;
}
