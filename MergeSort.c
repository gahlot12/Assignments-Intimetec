#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int leftIdx = left, rightIdx = mid + 1, tempIdx = 0;

    while (leftIdx <= mid && rightIdx <= right)
    {
        if (arr[leftIdx] <= arr[rightIdx])
        {
            temp[tempIdx++] = arr[leftIdx++];
        }
        else
        {
            temp[tempIdx++] = arr[rightIdx++];
        }
    }

    while (leftIdx <= mid)
    {
        temp[tempIdx++] = arr[leftIdx++];
    }

    while (rightIdx <= right)
    {
        temp[tempIdx++] = arr[rightIdx++];
    }

    for (int i = 0; i < size; i++)
    {
        arr[left + i] = temp[i];
    }

    free(temp);
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
