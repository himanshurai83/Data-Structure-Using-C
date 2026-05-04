#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rare = -1;
int isFull()
{
    if (rare == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (rare == -1)
        return 1;
    else
        return 0;
}
void display()
{
    if (front < 0)
    {
        printf("The Queue is empty....");
    }
    else
    {
        printf("Printing the Queue element\n");
        for (int i = 0; i <= rare; i++)
        {
            printf("| %d |", queue[i]);
        }
    }
}
void enqueue()
{
    if (isFull())
        printf("The Queue is full....");
    else
    {
        printf("Inserting in Queue...\n");
        int data;
        printf("Enter the data for insertion: ");
        scanf("%d", &data);
        rare = rare + 1;
        queue[rare] = data;
        if (rare == 0)
            front = 0;
    }
}
void dequeue()
{
    if (isEmpty())
        printf("The queue is Empty...");
    else
    {
        printf("Deleting in Queue...");
        int data = queue[0];
        for (int i = 0; i < rare; i++)
        {
            queue[i] = queue[i + 1];
        }
        rare--;
        printf("\n%d is deleted from the queue..", data);
    }
}
void count()
{
    printf("Total Count in Queue: %d", rare + 1);
}
void frontElement()
{

    printf("Front element in Queue: %d", queue[front]);
}
void rareElement()
{

    printf("Rare element in Queue: %d", queue[rare]);
}

int main()
{
    printf("Welcome to Queue..");
    while (1)
    {
        int choice;
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
        else
        {

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
                rareElement();
                break;
            default:
                printf("Enter a valid choice: ");
                break;
            }
        }
        printf("\n\n");
    }
    printf("Thanks for using this app.Hope! you enjoy it...");
}