#include <stdio.h>
#define Max_Size 100
int size;

void traverseArr(int arr[])
{
    printf("The array element are\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insertArr(int arr[])
{
    int pos, val;
    printf("Enter the position of element: ");
    scanf("%d", &pos);
    if (pos < 0 || size < pos + 2)
    {
        printf("Invalid Postion(Inserting)");
        return;
    }
    printf("Enter the value of element: ");
    scanf("%d", &val);

    for (int i = size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
    printf("Element insert successfully!\n");
    traverseArr(arr);
}

void updateArr(int arr[])
{
    int pos, val;
    printf("Enter the position of element: ");
    scanf("%d", &pos);
    printf("Enter the value of element: ");
    scanf("%d", &val);
    if (pos < 0 || pos < size + 2)
    {
        printf("Invalid Postion(Updating)");
        return;
    }
    arr[pos] = val;
    traverseArr(arr);
}

void deleteArr(int arr[])
{
    int pos, val;
    printf("Enter the position of element: ");
    scanf("%d", &pos);
    if (pos < 0 || pos < size + 2)
    {
        printf("Invalid Postion(Deleting)");
        return;
    }
    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    traverseArr(arr);
}
void sortArr(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            int tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
    }
    traverseArr(arr);
}
int main()
{
    printf("Welcome to the array operations\n");
    int choice;
    int arr[Max_Size];
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid Postion(Main)");
        return 0;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("Enter arr[%d] element: ", i);
            scanf("%d", &arr[i]);
        }
    }
    while (1)
    {
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 6)
            break;
        switch (choice)
        {
        case 1:
            traverseArr(arr);
            break;
        case 2:
            insertArr(arr);
            break;
        case 3:
            updateArr(arr);
            break;
        case 4:
            deleteArr(arr);
            break;
        case 5:
            sortArr(arr);
            break;
        }
    }
    printf("Thanks for using!");
}