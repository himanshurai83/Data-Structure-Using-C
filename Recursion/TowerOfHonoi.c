#include <stdio.h>
#include <math.h>

void TOH(char A, char B, char C, int n)
{
    if (n == 1)
    {
        printf("Disk %d moves from %c -> %c\n", n, A, B);
        return;
    }
    else
    {
        TOH(A, C, B, n - 1);
        printf("Disk %d move from %c -> %c\n", n, A, B);
        TOH(C, B, A, n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n != 0)
    {
        TOH('A', 'B', 'C', n);
        int total_moves = (int)pow(2, n) - 1;
        printf("Total moves are: %d", total_moves);
    }
    else
    {
        printf("There is no disk for move");
    }
}