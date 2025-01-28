#include <stdio.h>
#include <stdlib.h>

void performLinearSearch(int *arr, int target, int size)
{
    int found = 0;
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == target)
        {
            printf("Target found at index %d\n", index);
            found = 1;
            break;
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

    performLinearSearch(arr, target, size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
