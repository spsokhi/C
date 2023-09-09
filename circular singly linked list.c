#include <stdio.h>
#include <stdlib.h>

struct CircNode
{
    int data;
    struct CircNode *link;
};

struct CircNode *head;

void insertAtBeginning(int data)
{
    struct CircNode *newNode = malloc(sizeof(struct CircNode));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        struct CircNode *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        newNode->link = head;
        temp->link = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    struct CircNode *newNode = malloc(sizeof(struct CircNode));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        struct CircNode *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = head;
    }
}

void insertAtPos(int pos, int data)
{
    if (pos == 0)
    {
        insertAtBeginning(data);
        return;
    }

    struct CircNode *newNode = malloc(sizeof(struct CircNode));
    newNode->data = data;

    struct CircNode *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            free(newNode);
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

    struct CircNode *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }

    if (temp == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp->link = head->link;
        free(head);
        head = temp->link;
    }
}

void deleteAtPos(int pos)
{
    if (pos == 0)
    {
        deleteAtBeginning();
        return;
    }

    struct CircNode *temp = head;
    struct CircNode *pre = NULL;

    for (int i = 1; i <= pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        pre = temp;
        temp = temp->link;
    }
    pre->link = temp->link;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        return;
    }

    struct CircNode *temp = head;
    struct CircNode *pre = NULL;
    while (temp->link != head)
    {
        pre = temp;
        temp = temp->link;
    }

    if (pre == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        pre->link = head;
        free(temp);
    }
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct CircNode *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);
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

    // printf("Insertion at position\n");
    // insertAtPos(1, 25);
    // insertAtPos(0, 2);
    // displayList();

    // printf("Insertion at end\n");
    // insertAtEnd(6);
    // displayList();

    // printf("Deletion at position\n");
    // deleteAtPos(1);
    // displayList();

    // printf("Deletion at beginning\n");
    // deleteAtBeginning();
    // displayList();

    // printf("Deletion at end\n");
    // deleteAtEnd();
    // displayList();

    return 0;
}
