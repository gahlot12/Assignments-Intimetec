// 2. Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10

#include <stdio.h>
#include <stdlib.h>

void findMaxConsecutiveOnes(int *nums, int elements, int k)
{
    int left = 0;
    int right = 0;

    int zeroCount = 0;
    int maxLength = 0;

    while (right < elements)
    {
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (nums[left] == 0)
            {
                zeroCount--;
            }
            left++;
        }
        int curLength = right - left + 1;
        if (curLength > maxLength)
        {
            maxLength = curLength;
        }
        right++;
    }

    printf("%d\n", maxLength);
}

int main()
{
    int elements;
    scanf("%d", &elements);

    int k;
    scanf("%d", &k);

    int *nums = (int *)malloc(elements * sizeof(int));

    for (int i = 0; i < elements; i++)
    {
        scanf("%d", &nums[i]);
    }

    findMaxConsecutiveOnes(nums, elements, k);

    return 0;
}