#include <stdio.h>

long long calculatePowerModulo(long long number, long long power, long long modulus)
{
    if (power == 0)
        return 1;

    number = number % modulus;

    long long halfPowerResult = calculatePowerModulo(number, power / 2, modulus);

    long long squaredResult = halfPowerResult * halfPowerResult;

    squaredResult = squaredResult % modulus;

    if (power % 2 == 1)
    {
        squaredResult = squaredResult * number;
        squaredResult = squaredResult % modulus;
    }

    return squaredResult;
}

int main()
{
    long long B, N, M;

    printf("Enter the base B: ");
    scanf("%lld", &B);

    printf("Enter the exponent N: ");
    scanf("%lld", &N);

    printf("Enter the modulus M: ");
    scanf("%lld", &M);

    if (M == 0)
    {
        printf("Modulus cannot be zero.\n");
        return 1;
    }

    long long finalResult = calculatePowerModulo(B, N, M);
    printf("Result %lld\n", finalResult);

    return 0;
}