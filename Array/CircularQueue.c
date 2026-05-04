#include <stdio.h>
#define MAX_SIZE 100

int Circular_Queue[MAX_SIZE];
int front = -1, rear = -1;
int size;

void display()
{
    if (rear < 0)
    {
        printf("Queue is Empty...");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("| %d | ", Circular_Queue[i]);
        }
    }
}

void enqueue()
{
    if (((rear + 1) % size) == front)
        printf("Queue is Full !overflow condition occurs!\n");
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            Circular_Queue[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            Circular_Queue[rear] = data;
        }
    }
}

void dequeue()
{
    int data = Circular_Queue[front];
    if (front == rear)
    {
        printf("Now Queue is Empty!..\n");
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
        printf("%d element delete from the Queue\n", data);
    }
}

void count()
{
    int count = (rear - front + size) % size + 1;
    printf("Total element in the Queue is : %d\n", count);
}
void frontElement()
{
    printf("The Front element of the Queue : %d\n", Circular_Queue[front]);
}
void rearElement()
{
    printf("The Front element of the Queue : %d\n", Circular_Queue[rear]);
}

int main()
{
    printf("! Welcome to the circular !\n");
    int choice;
    printf("Enter the actual size that you use: ");
    scanf("%d", &size);
    while (1)
    {
        printf("\n1. for Display Queue");
        printf("\n2. for Enqueue");
        printf("\n3. for Dequeue");
        printf("\n4. for count");
        printf("\n5. for Front");
        printf("\n6. for Rare");
        printf("\n7. for Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 7)
            break;

        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            count();
            break;
        case 5:
            frontElement();
            break;
        case 6:
            rearElement();
            break;
        default:
            printf("Please enter a valid input!!\n");
        }
    }
    printf("Thanks for using this app....Hope! you love it..");
}