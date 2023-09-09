#include <stdio.h>
#include <stdlib.h>

struct DubNode
{
    int data;
    struct DubNode *prev;
    struct DubNode *next;
};

struct DubNode *head = NULL;
struct DubNode *tail = NULL;

void insertAtBegin(int data)
{
    struct DubNode *newDubNode = malloc(sizeof(struct DubNode));
    newDubNode->data = data;
    newDubNode->prev = NULL;

    if (head == NULL)
    {
        newDubNode->next = NULL;
        head = newDubNode;
        tail = newDubNode;
    }
    else
    {
        newDubNode->next = head;
        head->prev = newDubNode;
        head = newDubNode;
    }
}

void insertAtEnd(int data)
{
    struct DubNode *newDubNode = malloc(sizeof(struct DubNode));
    newDubNode->data = data;
    newDubNode->next = NULL;

    if (head == NULL)
    {
        newDubNode->prev = NULL;
        head = newDubNode;
        tail = newDubNode;
        return;
    }
    tail->next = newDubNode;
    newDubNode->prev = tail;
    tail = newDubNode;
}

void insertAtPos(int pos, int data)
{
    if (pos == 0)
    {
        insertAtBegin(data);
        return;
    }

    struct DubNode *newDubNode = malloc(sizeof(struct DubNode));
    newDubNode->data = data;

    struct DubNode *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid input\n");
            return;
        }
    }
    newDubNode->next = temp->next;
    temp->next->prev = newDubNode;
    newDubNode->prev = temp;
    temp->next = newDubNode;
}

void deleteAtBegin()
{
    struct DubNode *temp = head;
    head = temp->next;
    temp->next = NULL;
    head->prev = NULL;
    free(temp);
}
void deleteAtEnd()
{
    struct DubNode *temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    free(temp);
}
void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 0)
    {
        deleteAtBegin();
        return;
    }

    struct DubNode *temp = head;
    struct DubNode *pre = NULL;
    for (int i = 1; i <= pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid input\n");
            return;
        }
        pre = temp;
        temp = temp->next;
    }

    pre->next = temp->next;
    temp->next->prev = pre;
    free(temp);
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct DubNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayRevList()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct DubNode *temp = tail;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    printf("Insertion at beginning\n");
    insertAtBegin(5);
    insertAtBegin(9);
    insertAtBegin(10);
    displayList();
    printf("Reverse doubly\n");
    displayRevList();

    printf("Insertion at end\n");
    insertAtEnd(6);
    insertAtEnd(99);
    displayList();
    printf("Reverse doubly\n");
    displayRevList();

    printf("Insertion at point\n");
    insertAtPos(2, 95);
    displayList();
    printf("Reverse doubly\n");
    displayRevList();

    printf("Deletion at beginning\n");
    deleteAtBegin();
    displayList();
    printf("Reverse doubly\n");
    displayRevList();

    printf("deletion at end\n");
    deleteAtEnd();
    displayList();
    printf("Reverse Doubly\n");
    displayRevList();

    printf("Deletion at pos\n");
    deleteAtPos(1);
    displayList();
    printf("Reverse doubly\n");
    displayRevList();

    return 0;
}
