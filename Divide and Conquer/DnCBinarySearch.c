#include <stdio.h>

int binarySearch(int arr[], int x, int low, int high)
{
    int mid;
    if(low > high)
        return -1;
    else
    {
        mid = (low + high) / 2;
        if(x == arr[mid])
            return mid;
        else if(x > arr[mid])
            return binarySearch(arr, x, mid + 1, high);
        else
            return binarySearch(arr, x, low, mid);
    }
}

void main()
{
    int i, n, x;
    printf("Binary Search\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array in a sorted manner: \n");
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to be searched: ");
    scanf("%d",&x);
    int index = binarySearch(arr, x, 0, n - 1);
    printf("\nElement %d has been found at index %d", x, index);
}