// DnC - Min Max Problem
#include <stdio.h>

int max(int y, int z)
{ 
    if(y > z)
        return y;
    else 
        return z;
}

int min(int y, int z)
{ 
    if(y < z)
        return y;
    else 
        return z;
}

int find_max(int arr[], int l, int h)
{
    int mid;
    int size = h - l + 1;
    if(size == 1)
        return(arr[l]);
    else if(size == 2)
        return(max(arr[l],arr[h]));
    else
        mid = (l + h) / 2;
        int maximum = max(find_max(arr, 0, mid),find_max(arr, mid + 1, h));
    return(maximum);
}

int find_min(int arr[], int l, int h)
{
    int mid;
    int size = h - l + 1;
    if(size == 1)
        return(arr[l]);
    else if(size == 2)
        return(min(arr[l],arr[h]));
    else
        mid = (l + h) / 2;
        int minimum = min(find_min(arr, 0, mid),find_min(arr, mid + 1, h));
    return(minimum);
}

int main()
{
    int n, maxElement, minElement;
    printf("Finding out minimum and maximum element in an Array using Divide and Conquer");
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array: \n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    maxElement = find_max(arr, 0, n - 1);
    minElement = find_min(arr, 0, n - 1);
    printf("\nMaximum Element = %d",maxElement);
    printf("\nMinimum Element = %d",minElement);
}