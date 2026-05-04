#include <stdio.h>

int printingElement(int arr[], int len, int indx)
{
    if (len < indx)
        return 0;
    else
    {
        printf("%d\t", arr[indx]);
        return printingElement(arr, len, indx + 1);
    }
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
    int result = printingElement(arr, size - 1, 0);
    return 0;
}