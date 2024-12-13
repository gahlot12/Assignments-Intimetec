#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int myIsDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int myIsSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int precedence(char operator)
{
    return (operator== '+' || operator== '-') ? 1 : (operator== '*' || operator== '/') ? 2
                                                                                       : 0;
}

void handleError(int flag)
{
    if (flag == 1)
        printf("Error: Invalid character in expression.\n");
    else if (flag == 2)
        printf("Error: Division by zero is not allowed.\n");
    else
        printf("Error: Invalid expression.\n");
}

int main(int argc, char const *argv[])
{
    char str[MAX_LEN];
    printf("Enter a string for calculation: \n");
    if (!fgets(str, MAX_LEN, stdin) || strlen(str) <= 1)
    {
        printf("Error: No input provided.\n");
        return 1;
    }

    int stack[MAX_LEN];
    char operators[MAX_LEN];
    int topStack = -1;
    int topOperators = -1;
    int flag = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (myIsSpace(str[i]))
            continue;

        if (myIsDigit(str[i]))
        {
            int num = 0;
            while (myIsDigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            stack[++topStack] = num;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (topOperators >= 0 && precedence(operators[topOperators]) >= precedence(str[i]))
            {
                int b = stack[topStack--];
                int a = stack[topStack--];
                char op = operators[topOperators--];

                if (op == '/' && b == 0)
                {
                    flag = 2;
                    break;
                }

                stack[++topStack] = (op == '+') ? a + b : (op == '-') ? a - b
                                                      : (op == '*')   ? a * b
                                                                      : a / b;
            }
            operators[++topOperators] = str[i];
        }
        else
        {
            flag = 1;
            break;
        }
    }

    while (topOperators >= 0 && flag == 0)
    {
        int b = stack[topStack--];
        int a = stack[topStack--];
        char op = operators[topOperators--];

        if (op == '/' && b == 0)
        {
            flag = 2;
            break;
        }

        stack[++topStack] = (op == '+') ? a + b : (op == '-') ? a - b
                                              : (op == '*')   ? a * b
                                                              : a / b;
    }

    if (flag)
        handleError(flag);
    else
        printf("Answer: %d\n", stack[topStack]);

    return 0;
}
