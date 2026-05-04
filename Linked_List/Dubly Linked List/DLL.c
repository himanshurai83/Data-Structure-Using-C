#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Creating a New Node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert Node at the begining
struct Node *insertAtBegining(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
    }
    return head;
}

// Insert Node at the ending
struct Node *insertAtEnding(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Insert Node at the specific location
struct Node *insertAtSpecific(struct Node *head, int value, int position)
{
    if (position == 1)
    {
        head = insertAtBegining(head, value);
    }
    else
    {
        struct Node *newNode = createNode(value);
        struct Node *temp = head;
        int i = 1;
        while (temp != NULL && i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("Invalid Position\n");
        }
        else
        {
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    return head;
}

// Delete Node from the begining

struct Node *deleteFromBegining(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty..\n");
    }
    else if (head->next == head->prev)
    {
        printf("Only one Node present,Now all the list is Empty..");
        head = NULL;
        free(temp);
    }
    else
    {
        head = temp->next;
        temp->prev = NULL;
    }
    return head;
}

struct Node *deleteFromEnding(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty..\n");
    }
    else if (head->next == NULL)
    {
        printf("Only one Node present,Now all the list is Empty..");
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    return head;
}

struct Node *deleteFromSpecific(struct Node *head, int position)
{
    if (position == 1)
    {
        head = deleteFromBegining(head);
    }
    else
    {
        struct Node *temp = head;
        int i = 1;
        while (temp != NULL && i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position\n");
        }
        else
        {
            struct Node *delNode = temp->next;
            if (delNode->next == NULL)
                temp->next = NULL;
            else
            {
                temp->next = delNode->next;
                delNode->next->prev = temp;
            }
            free(delNode);
        }
    }
    return head;
}

void traversal(struct Node *head)
{
    printf("\n");
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is Empty..\n");
    }
    else
    {
        printf("NULL");
        while (temp != NULL)
        {
            printf(" <- %d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main()
{
    struct Node *head = NULL;
    int choice;
    while (1)
    {
        printf("\n1. for Insert at Begining\n");
        printf("2. for Insert at Ending\n");
        printf("3. for Insert at Specific Location\n");
        printf("4. for Delete from Begining\n");
        printf("5. for Delete from Ending\n");
        printf("6. for Delete from Specific Location\n");
        // printf("7. for Total Node count\n");
        // printf("8. for Search any Node with their key\n");
        printf("9. for Exit\n");
        printf("Choice your options: ");
        scanf("%d", &choice);

        if (choice == 9)
            break;
        int value, position;
        switch (choice)
        {
        case 1:
            printf("Enter the value want to insert: ");
            scanf("%d", &value);
            head = insertAtBegining(head, value);
            traversal(head);
            break;
        case 2:
            printf("Enter the value want to insert: ");
            scanf("%d", &value);
            head = insertAtEnding(head, value);
            traversal(head);
            break;
        case 3:

            printf("Enter the specific position: ");
            scanf("%d", &position);
            printf("Enter the value want to insert: ");
            scanf("%d", &value);
            head = insertAtSpecific(head, value, position);
            traversal(head);
            break;
        case 4:
            head = deleteFromBegining(head);
            traversal(head);
            break;
        case 5:
            head = deleteFromEnding(head);
            traversal(head);
            break;
        case 6:
            printf("Enter the specific position: ");
            scanf("%d", &position);
            head = deleteFromSpecific(head, position);
            traversal(head);
            break;
        // case 7:
        //     count(head);
        //     break;
        // case 8:
        //     printf("Enter the key,Which you want to search: ");
        //     scanf("%d", &value);
        //     int response = search(head, value);
        //     if (response)
        //     {
        //         printf("The Node present in %d position\n", response);
        //     }
        //     else
        //     {
        //         printf("The Node not present in the list\n");
        //     }
        //     break;
        default:
            printf("Choice the correct option..");
        }
    }

    printf("Thanks for using the list.Hope! you enjoy..");

    return 0;
}