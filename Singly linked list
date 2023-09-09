#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head;

void insertAtBeginning(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
}
void insertAtEnd(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}
void insertAtPos(int pos, int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *temp = head;
    if (pos == 0)
    {
        newNode->link = head;
        head = newNode;
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid input\n");
            return;
        }
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}
void deleteAtBeginning()
{
    if (head == NULL)
    {
        return;
    }
    struct Node *temp = head;
    head = temp->link;
    free(temp);
}
void deleteAtPos(int pos)
{
    if (pos == 0)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    struct Node *pre = NULL;

    for (int i = 1; i <= pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid input\n");
            return;
        }
        pre = temp;
        temp = temp->link;
    }
    pre->link = temp->link;
    free(temp);
}
void deletionAtEnd()
{
    struct Node *temp = head;
    struct Node *pre = NULL;
    while (temp->link != NULL)
    {
        pre = temp;
        temp = temp->link;
    }
    pre->link = NULL;
}
void displayList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    printf("Insertion at beginning\n");
    insertAtBeginning(5);
    insertAtBeginning(9);
    insertAtBeginning(10);
    displayList();

    printf("Insertion at position\n");
    insertAtPos(1, 25);
    insertAtPos(0, 2);
    displayList();

    printf("Insertion at end\n");
    insertAtEnd(6);
    displayList();

    printf("Deletion at position\n");
    deleteAtPos(1);
    displayList();

    printf("Deletion at beginning\n");
    deleteAtBeginning();
    displayList();
    printf("Deletion at end\n");
    deletionAtEnd();
    displayList();

    return 0;
}
