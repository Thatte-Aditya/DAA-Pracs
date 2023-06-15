#include <stdio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int wt[], int val[], int n) 
{
    if (capacity == 0 || n == 0)
        return 0;
    if (wt[n - 1] > capacity)
        return knapsack(capacity, wt, val, n - 1);

    return max(val[n - 1] + knapsack(capacity - wt[n - 1], wt, val, n - 1),
               knapsack(capacity, wt, val, n - 1));
}

void knapsackWithItems(int capacity, int wt[], int val[], int n, int selected[]) 
{
    if (capacity == 0 || n == 0)
        return;

    if (wt[n - 1] > capacity)
        knapsackWithItems(capacity, wt, val, n - 1, selected);
    else {
        int includedValue = val[n - 1] + knapsack(capacity - wt[n - 1], wt, val, n - 1);
        int excludedValue = knapsack(capacity, wt, val, n - 1);

        if (includedValue >= excludedValue) {
            selected[n - 1] = 1; // Mark item as selected
            knapsackWithItems(capacity - wt[n - 1], wt, val, n - 1, selected);
        } else {
            selected[n - 1] = 0; // Mark item as not selected
            knapsackWithItems(capacity, wt, val, n - 1, selected);
        }
    }
}

int main() 
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int value[n], weight[n];
    for (int i = 0; i < n; i++) 
    {
        printf("Enter value for Item %d: ", i + 1);
        scanf("%d", &value[i]);
        printf("Enter weight for Item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }
    int capacity;
    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    int selected[n]; // Array to store whether an item is selected (1) or not (0)
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    knapsackWithItems(capacity, weight, value, n, selected);

    printf("\nSelected items:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i] == 1)
            printf("Item %d\n", i + 1);
    }

    printf("\nValue = %d\n", knapsack(capacity, weight, value, n));
    return 0;
}