#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Stack structure
struct Stack
{
    struct Node *top;
};

void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, int element)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Error: Stack is empty, cannot pop element\n");
        return -1;
    }

    struct Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Error: Stack is empty, cannot peek\n");
        return -1;
    }

    return stack->top->data;
}

void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *current = stack->top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Peeked element: %d\n", peek(&stack));

    display(&stack);

    return 0;
}
