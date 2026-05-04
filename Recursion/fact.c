#include <stdio.h>

int factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        int s = num * factorial(num - 1);
        return s;
    }
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Factorial is : %d", result);
    return 0;
}