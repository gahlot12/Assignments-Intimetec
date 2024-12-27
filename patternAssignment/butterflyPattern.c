#include <stdio.h>

void printPattern(int size)
{
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("%d", col);
        }
        for (int space = 1; space <= (2 * (size - row)); space++)
        {
            printf(" ");
        }
        for (int col = row; col >= 1; col--)
        {
            printf("%d", col);
        }
        printf("\n");
    }

    for (int row = size - 1; row >= 1; row--)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("%d", col);
        }
        for (int space = 1; space <= (2 * (size - row)); space++)
        {
            printf(" ");
        }
        for (int col = row; col >= 1; col--)
        {
            printf("%d", col);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    printPattern(n);

    return 0;
}