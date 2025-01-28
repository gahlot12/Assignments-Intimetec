#include <stdio.h>
#include <stdlib.h>

void performBinarySearch(int *arr, int target, int size)
{
    int left = 0, right = size - 1;
    int found = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d\n", mid);
            found = 1;
            break;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!found)
    {
        printf("Target not found\n");
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    int target;
    scanf("%d", &target);

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

    performBinarySearch(arr, target, size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
