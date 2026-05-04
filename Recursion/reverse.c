#include <stdio.h>

int reverseOfDigit(int n, int rev)
{
    if (n == 0)
        return rev;
    else
        return reverseOfDigit(n / 10, 10 * rev + n % 10);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = reverseOfDigit(n, 0);
    printf("Fibonacci is : %d", result);
    return 0;
}