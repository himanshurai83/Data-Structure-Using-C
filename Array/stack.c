#include <stdio.h>
#define MAX_SIZE 10
int arr[MAX_SIZE];
int size;
int isFull = 0, isEmpty = MAX_SIZE;
void checkStackSpace();
void inputStack()
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter arr[%d] element: ", i);
        scanf("%d", &arr[i]);
    }
    isFull = size;
    isEmpty = 100 - size;
}

void traverseStack()
{
    for (int i = 0; i < size; i++)
    {
        printf("| %d |", arr[i]);
    }
    checkStackSpace();
}

void pushStack()
{
    if (isFull == MAX_SIZE)
    {
        printf("Stack is full! Overflow condition occurs.\n");
    }
    else
    {
        int value;
        printf("Enter value: ");
        scanf("%d", &value);
        arr[size] = value;
        size++;
        isFull++;
        isEmpty--;
        printf("Pushed element are: %d\n", value);
        printf("Successfully pushed!");
        checkStackSpace();
    }
}

void popStack()
{
    if (isFull == 0)
    {
        printf("Stack is empty! underflow condition occurs..\n");
    }
    else
    {
        int popElement = arr[size - 1];
        size--;
        isEmpty++;
        isFull--;
        printf("Pop element are: %d\n", popElement);
        printf("Successfully popped!");
        checkStackSpace();
    }
}

void sortStack()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    printf("Stack sorted successfully\n");
}

void stackPeek()
{
    if (isFull == 0)
        printf("The stack is empty!...");
    else
        printf("Top element of the stack is: %d", arr[size - 1]);
}
void checkStackSpace()
{
    printf("\nStack Full area: %d", isFull);
    printf("\nStack Empty area: %d", isEmpty);
}
void stackCount()
{
    printf("Total element in the stack is: %d\n", isFull);
}
int main()
{
    // printf("Enter the size of an array: ");
    // scanf("%d", &size);
    // if (size <= 0 || size > MAX_SIZE)
    // {
    //     printf("Invalid array size!");
    // }
    // else
    // {
    //     inputStack();
    // }

    int choice;
    printf("\n\n");
    while (1)
    {
        printf("\n1. for Display Stack");
        printf("\n2. for Push");
        printf("\n3. for Pop");
        printf("\n4. for Sort");
        printf("\n5. for Peek");
        printf("\n6. for Check Stack Space");
        printf("\n7. for Check Stack Count");
        printf("\n8. for Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 8)
            break;
        else
        {

            switch (choice)
            {
            case 1:
                traverseStack();
                break;
            case 2:
                pushStack();
                break;
            case 3:
                popStack();
                break;
            case 4:
                sortStack();
                break;
            case 5:
                stackPeek();
                break;
            case 6:
                checkStackSpace();
                break;
            case 7:
                stackCount();
                break;
            default:
                printf("Enter a valid choice: ");
                break;
            }
        }
        printf("\n\n");
    }

    return 0;
}
