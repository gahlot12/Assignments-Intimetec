#include <stdio.h>
#include <stdlib.h>

void swapElements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionArray(int arr[], int lowIdx, int highIdx)
{
    int pivotValue = arr[lowIdx];

    int smallerElementsCount = 0;
    for (int i = lowIdx + 1; i <= highIdx; i++)
    {
        if (arr[i] <= pivotValue)
        {
            smallerElementsCount++;
        }
    }

    int pivotIndex = lowIdx + smallerElementsCount;
    swapElements(&arr[pivotIndex], &arr[lowIdx]);

    int start = lowIdx, end = highIdx;

    while (start <= end)
    {
        while (arr[start] < pivotValue && start < highIdx)
            start++;
        while (arr[end] > pivotValue && end > lowIdx)
            end--;

        if (start <= end)
        {
            swapElements(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }

    return pivotIndex;
}

void performQuickSort(int arr[], int leftIdx, int rightIdx)
{
    if (leftIdx >= rightIdx)
        return;

    int pivotIndex = partitionArray(arr, leftIdx, rightIdx);

    performQuickSort(arr, leftIdx, pivotIndex - 1);
    performQuickSort(arr, pivotIndex + 1, rightIdx);
}

int main()
{
    int size;

    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    performQuickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
