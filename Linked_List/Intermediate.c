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

struct Node *insertAtBegining(struct Node *head, int value)
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
    }
    return head;
}

struct Node *insertAtSpecific(struct Node *head, int value, int position)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    int i = 1;
    while (temp != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *deleteFromBegining(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is already empty!\n");
    }
    else if (head->next == NULL)
    {
        printf("Only one node is present,Now whole list is empty!\n");
        free(head);
        return NULL;
    }
    else
    {
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node *deleteFromEnding(struct Node *head)
{
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node *deleteFromSpecific(struct Node *head, int position)
{
    int i = 1;
    struct Node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        free(temp);
    }
    while (temp != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }
    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}
int search(struct Node *head, int key)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return 0;
}
void count(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("Total Nodes are: %d\n", count);
}

void traversal(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
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
        printf("7. for Total Node count\n");
        printf("8. for Search any Node with their key\n");
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
        case 7:
            count(head);
            break;
        case 8:
            printf("Enter the key,Which you want to search: ");
            scanf("%d", &value);
            int response = search(head, value);
            if (response)
            {
                printf("The Node present in %d position\n", response);
            }
            else
            {
                printf("The Node not present in the list\n");
            }
            break;
        default:
            printf("Choice the correct option..");
        }
    }

    printf("Thanks for using the list.Hope! you enjoy..");

    return 0;
}