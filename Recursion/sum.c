#include <stdio.h>

int sumOfNaturalNumber(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sumOfNaturalNumber(n - 1);
}

int main()
{
    int n;
    printf("Enter the first n natural number: ");
    scanf("%d", &n);
    int result = sumOfNaturalNumber(n);
    printf("Fibonacci is : %d", result);
}