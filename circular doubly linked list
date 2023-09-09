#include <stdio.h>
#include <stdlib.h>

struct CircNode
{
    int data;
    struct CircNode *prev;
    struct CircNode *next;
};

struct CircNode *head;

void insertAtBeginning(int data)
{
    struct CircNode *newNode = malloc(sizeof(struct CircNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    struct CircNode *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct CircNode *newNode = malloc(sizeof(struct CircNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    struct CircNode *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
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
    newNode->next = NULL;
    newNode->prev = NULL;

    struct CircNode *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        return;
    }

    struct CircNode *temp = head;

    if (temp->next == temp)
    {
        free(temp);
        head = NULL;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head->next->prev = temp;
    free(head);
    head = temp->next;
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
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    temp->next->prev = pre;
    pre->next = temp->next;
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

    if (temp->next == head)
    {

        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != head)
    {
        pre = temp;
        temp = temp->next;
    }

    pre->next = head;
    head->prev = pre;

    // temp->prev->next = head;
    // head->prev = temp->prev;

    free(temp);
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
        temp = temp->next;
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

    printf("Insertion at end\n");
    insertAtEnd(6);
    displayList();

    printf("Insertion at position\n");
    insertAtPos(1, 25);
    insertAtPos(0, 2);
    displayList();

    printf("Deletion at position\n");
    deleteAtPos(2);
    displayList();

    printf("Deletion at beginning\n");
    deleteAtBeginning();
    displayList();

    printf("Deletion at end\n");
    deleteAtEnd();
    displayList();
    return 0;
}
