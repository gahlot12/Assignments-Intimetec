#include <stdio.h>
#include <string.h>

int getRowInput()
{
    int row;
    printf("Enter number of rows :\n");
    scanf("%d", &row);
    while (row < 1 || row > 10)
    {
        printf("Invalid input. Enter the number of rows (1-10):\n");
        scanf("%d", &row);
    }
    return row;
}

int getColInput()
{
    int col;
    printf("Enter the number of columns :\n");
    scanf("%d", &col);
    while (col < 1 || col > 101)
    {
        printf("Invalid input. Enter the number of columns (1-101):\n");
        scanf("%d", &col);
    }
    return col;
}

void readNames(char arr[][101][50], int row, int col)
{
    printf("Enter the names:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", arr[i][j]);
        }
    }
}

void printNames(char arr[][101][50], int row, int col)
{
    printf("2D array of names in matrix format:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s\t", arr[i][j]);
        }
        printf("\n");
    }
}

int countVowelNames(char arr[][101][50], int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char firstChar = arr[i][j][0];
            if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' ||
                firstChar == 'o' || firstChar == 'u' || firstChar == 'A' ||
                firstChar == 'E' || firstChar == 'I' || firstChar == 'O' ||
                firstChar == 'U')
            {
                count++;
            }
        }
    }
    return count;
}

void findLongestName(char arr[][101][50], int row, int col, char *longestName)
{
    int maxLength = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int length = 0;
            while (arr[i][j][length] != '\0')
            {
                length++;
            }

            if (length > maxLength)
            {
                maxLength = length;
                int k = 0;
                while (arr[i][j][k] != '\0')
                {
                    longestName[k] = arr[i][j][k];
                    k++;
                }
                longestName[k] = '\0';
            }
        }
    }
}

int main()
{
    int row, col;

    row = getRowInput();
    col = getColInput();

    char arr[10][101][50];

    readNames(arr, row, col);

    printNames(arr, row, col);

    int vowelCount = countVowelNames(arr, row, col);
    printf("Number of names starting with a vowel: %d\n", vowelCount);

    char longestName[50];
    findLongestName(arr, row, col, longestName);
    printf("The longest name is: %s\n", longestName);

    return 0;
}
