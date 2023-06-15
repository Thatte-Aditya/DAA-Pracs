#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{
    for(int i = 0 ; i < n; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

void main()
{
    int i, n, x;
    printf("Linear Search\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array: \n");
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to be searched: ");
    scanf("%d",&x);
    int index = linearSearch(arr, n, x);
    if(index != -1)
        printf("\nElement %d has been found at index %d", x, index);
    else
        printf("\nElement not found");
}