// 1. Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findMaxDiff(int *nums, int elements)
{

    for (int i = 0; i < elements - 1; i++)
    {
        for (int j = i; j < elements - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int maxDiff = INT_MIN;

    for (int i = 0; i < elements - 1; i++)
    {
        int diff = nums[i + 1] - nums[i];
        if (diff > maxDiff)
        {
            maxDiff = nums[i + 1] - nums[i];
        }
    }

    printf("%d", maxDiff);
}

int main()
{
    int elements;
    scanf("%d", &elements);

    if (elements < 2)
    {
        printf("0\n");
        return 0;
    }

    int *nums = (int *)malloc(elements * sizeof(int));

    for (int i = 0; i < elements; i++)
    {
        scanf("%d", &nums[i]);
    }

    findMaxDiff(nums, elements);

    return 0;
}