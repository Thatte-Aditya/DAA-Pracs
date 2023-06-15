// Greedy - Coin Changing
#include <stdio.h>
#define COINS 5
#define MAX 20

int coins[COINS] = { 1, 2, 5, 10, 20 };

void findMin(int cost)
{
	int coinList[MAX] = { 0 };
	int i, k = 0;
	for (i = COINS - 1; i >= 0; i--) 
	{
		while (cost >= coins[i]) 
		{
			cost -= coins[i];
			// Add coin in the list
			coinList[k++] = coins[i];
		}
	}
	for (i = 0; i < k; i++) 
	{
		printf("%d ", coinList[i]);
	}
}

int main()
{
	int n;
    printf("Coin Changing Algorithm using Greedy approach\nEnter the value: ");
    scanf("%d",&n);
	printf("Following is minimal number of change for %d: ", n);
	findMin(n);
	return 0;
}