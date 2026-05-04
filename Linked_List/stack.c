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

struct Node *push(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node *pop(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Stack is empty..\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Only one element present in the stack, Now its Empty.\n");
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

int count(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void topElement(struct Node *head)
{
    if (head == NULL)
        printf("Stack is empty!\n");
    else
    {
        printf("Top element of the stack is: %d\n", head->data);
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Stack is Empty..\n");
    }
    while (temp != NULL)
    {
        printf("| %d |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    printf("Welcome to the Stack using Linked list...\n");
    struct Node *head = NULL;
    int value, choice;
    while (1)
    {
        printf("1. for display Elements\n");
        printf("2. for PUSH operation\n");
        printf("3. for POP operation\n");
        printf("4. for Total count\n");
        printf("5. for Top\n");
        printf("6. for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6)
            break;
        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("Enter value for push: ");
            scanf("%d", &value);
            head = push(head, value);
            break;
        case 3:
            head = pop(head);
            break;
        case 4:
            printf("Total Element inside the stack is: %d\n", count(head));
            break;
        case 5:
            topElement(head);
            break;
        default:
            printf("Choice the correct option..\n");
        }
    }
    printf("Thanks for using this app. Hope! you enjoy it..");
    return 0;
}