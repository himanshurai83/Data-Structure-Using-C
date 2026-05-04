#include <stdio.h>
#define MAX_SIZE 100
int Queue[MAX_SIZE];
int front = -1, rear = -1;

void display()
{
    if (front < 0)
        printf("Queue is Empty...");
    else
    {
        for (int i = 0; i <= rear; i++)
        {
            printf("| %d |", Queue[i]);
        }
    }
}

void enqueue()
{
    if (rear > MAX_SIZE - 1)
        printf("Queue is full. Overflow condition\n");
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            Queue[rear] = data;
        }
        else
        {
            rear = rear + 1;
            Queue[rear] = data;
        }
        printf("Front index: %d\n", front);
        printf("Rear index: %d\n", rear);
        printf("Element inserted successfully...\n");
    }
}

void dequeue()
{
    if (front > rear)
        printf("Queue is Empty..Underflow condition\n");

    else
    {

        int data = Queue[front];
        front += 1;
        printf("Deleted element from the queue is: %d\n", data);
        if (front > rear)
        {
            rear = front;
        }
        printf("Front index: %d\n", front);
        printf("Rear index: %d\n", rear);
    }
}

void count()
{
    int count = (rear - front) + 1;
    printf("Total element inside the Queue is: %d\n", count);
}
void frontElement()
{
    printf("Front element of the Queue is: %d\n", Queue[front]);
}
void rearElement()
{
    printf("Front element of the Queue is: %d\n", Queue[rear]);
}
int main()
{
    printf("! Welcome to the QueueWithoutShifting app !\n");
    int choice;
    while (1)
    {
        printf("\n1. for Display Queue\n");
        printf("2. for Enqueue\n");
        printf("3. for Dequeue\n");
        printf("4. for Count\n");
        printf("5. for Front\n");
        printf("6. for Rear\n");
        printf("7. for Exit\n");
        printf("Enter your choice: ");
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
            printf("Chose the valid choice....\n");
        }
    }
    printf("Thanks for using this app.Hope! you enjoy it...");
}