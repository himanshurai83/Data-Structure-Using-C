#include <stdio.h>

int countOfDigit(int n, int count)
{
    if (n == 0)
        return count;
    else
        return countOfDigit(n / 10, ++count);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = countOfDigit(n, 0);
    printf("Digit count is : %d", result);
    return 0;
}