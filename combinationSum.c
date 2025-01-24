// Given an array of distinct integers candidates and a target integer target, print all combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: 2 2 3
// 	      7

// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: 2 2 2 2
// 	      2 3 3
// 	      3 5

// Example 3:

// Input: candidates = [2], target = 1
// Output:

#include <stdio.h>
#include <stdlib.h>

void combinationSum(int *candidates, int candidateSize, int target, int *cur, int currentSize, int startIndex)
{
    if (target == 0)
    {
        for (int i = 0; i < currentSize; i++)
        {
            printf("%d ", cur[i]);
        }
        printf("\n");
        return;
    }

    for (int i = startIndex; i < candidateSize; i++)
    {
        if (candidates[i] <= target)
        {
            cur[currentSize] = candidates[i];
            combinationSum(candidates, candidateSize, target - candidates[i], cur, currentSize + 1, i);
        }
    }
}

void findCombination(int *candidates, int candidateSize, int target)
{
    int *current = (int *)malloc(target * sizeof(int));
    combinationSum(candidates, candidateSize, target, current, 0, 0);
    free(current);
}

int main()
{
    int target;
    scanf("%d", &target);

    int n;
    scanf("%d", &n);

    int *candidates = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &candidates[i]);
    }

    findCombination(candidates, n, target);

    free(candidates);

    return 0;
}