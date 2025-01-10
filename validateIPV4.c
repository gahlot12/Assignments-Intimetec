// Problem Statement: Validate IPv4 Address
// Objective:
// Write a program in C to validate whether a given string is a valid IPv4 address.

// Requirements:
// 1. An IPv4 address consists of four decimal numbers separated by dots (.).
// Each number must be in the range 0 to 255.
// Leading zeros are not allowed unless the number is exactly 0.
//  Each number should be composed of digits only.
// Example of valid IPv4 addresses: 192.168.0.1, 127.0.0.1.
// Example of invalid IPv4 addresses: 256.256.256.256, 192.168.01.1, 192.168..1.

// 2. Constraints:
// The input string will be a maximum of 15 characters.
//  There will be no whitespace in the input.

// Input Format:
// A single string representing the IPv4 address.

// Output Format:
// A single line of output:
// * Print "Valid" if the input is a valid IPv4 address.
// * Print "Invalid" if the input is not a valid IPv4 address.

// Example:
// Input 1:
// 192.168.1.1
// Output 1:
// Valid
// Input 2:
// 256.256.256.256
// Output 2:
// Invalid
// Input 3:
// 192.168.01.1
// Output 3:
// Invalid
// Input 4:
// 192.168..1
// Output 4:
// Invalid

#include <stdio.h>
#include <stdlib.h>

int isValidPart(char *part, int length)
{
    if (length == 0 || length > 3)
        return 0;

    int value = 0;

    for (int i = 0; i < length; i++)
    {
        if (part[i] < '0' || part[i] > '9')
            return 0;
        value = value * 10 + (part[i] - '0');
    }
    if (value < 0 || value > 255)
        return 0;

    if (length > 1 && part[0] == '0')
        return 0;

    return 1;
}

int isValidIP(char *stringIP)
{

    int count = 0;
    int partstart = 0;
    int i = 0;

    while (stringIP[i] != '\0')
    {
        if (stringIP[i] == '.')
        {
            int partLength = i - partstart;

            if (!isValidPart(stringIP + partstart, partLength))
            {
                return 0;
            }
            count++;
            partstart = i + 1;
        }
        i++;
    }

    if (!isValidPart(stringIP + partstart, i - partstart))
        return 0;

    count++;

    return count == 4;
}

int main()
{
    char stringIP[16];
    scanf("%s", stringIP);

    if (isValidIP(stringIP))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}
