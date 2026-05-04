#include <stdio.h>

int arraySum(int arr[], int len)
{
    if (len <= -1)
        return 0;
    else
        return arr[len] + arraySum(arr, len - 1);
}

int main()
{
    int size;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter arr[%d] element: ", i);
        scanf("%d", &arr[i]);
    }
    int result = arraySum(arr, size - 1);
    printf("Sum of all element is: %d", result);
    return 0;
}