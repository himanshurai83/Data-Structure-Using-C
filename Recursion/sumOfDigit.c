#include <stdio.h>

int sumOfDigit(int n)
{
    if (n == 0)
        return 0;
    else
        return n % 10 + sumOfDigit(n / 10);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = sumOfDigit(n);
    printf("Fibonacci is : %d", result);
    return 0;
}