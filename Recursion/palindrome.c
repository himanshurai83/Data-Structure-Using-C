#include <stdio.h>

int reverse(int n, int rev, int tmp)
{
    if (n == 0)
    {
        if (tmp == rev)
            return 1;
        else
            return 0;
    }
    else
    {
        return reverse(n / 10, 10 * rev + n % 10, tmp);
    }
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = reverse(n, 0, n);
    if (result)
        printf("Number is palindrome!!");
    else
        printf("Number is not palindrome!!");
    return 0;
}