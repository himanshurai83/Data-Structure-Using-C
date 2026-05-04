#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *enqueue(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
struct Node *dequeue(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue is Fully empty!\n");
    }
    if (head->next == NULL)
    {
        printf("Only one element present inside the queue,Now Queue is fully Empty..\n");
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

void frontElement(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue is Empty..\n");
    }
    else
    {
        int data = head->data;
        printf("Front element of the Queue is: %d\n", data);
    }
}
void rearElement(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue is Empty..\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        int data = temp->data;
        printf("Rear Element of the Queue is: %d\n", data);
    }
}

void totalCount(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("Total element inside the Queue is: %d\n", count);
}

void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("| %d |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("Welcome to the Queue using Linked list...\n");
    struct Node *head = NULL;
    int value, choice;
    while (1)
    {
        printf("\n1. for Enqueue\n");
        printf("2. for Dequeue\n");
        printf("3. for Front\n");
        printf("4. for Rear\n");
        printf("5. for Total Count\n");
        printf("6. for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 6)
            break;
        switch (choice)
        {
        case 1:
            printf("Enter value for Enqueue: ");
            scanf("%d", &value);
            head = enqueue(head, value);
            traverse(head);
            break;
        case 2:
            head = dequeue(head);
            traverse(head);
            break;
        case 3:
            frontElement(head);
            break;
        case 4:
            rearElement(head);
            break;
        case 5:
            totalCount(head);
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    }
    printf("Thanks for using this app. Hope! you enjoy it..");
    return 0;
}