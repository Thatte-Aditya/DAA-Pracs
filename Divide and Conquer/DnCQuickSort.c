#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) 
        {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted // low --> Starting index // high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        // pi is partitioning index, arr[p] is now at right place
        int pIndex = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main()
{
    int n;
    printf("Quick Sort using Divide and Conquer approach\nEnter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}