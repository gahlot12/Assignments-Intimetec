#include <stdio.h>
#include <stdlib.h>

void performTwoPointerSearch(int *arr, int target, int size)
{
    int left = 0, right = size - 1;
    int found = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            found = 1;
            break;
        }
        if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
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

    performTwoPointerSearch(arr, target, size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
