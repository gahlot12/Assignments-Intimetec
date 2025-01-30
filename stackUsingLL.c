#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
    int size;
} Stack;

void initialiseStack(Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return stack->top->data;
}

int size(Stack *stack)
{
    return stack->size;
}

int main()
{
    Stack stack;
    initialiseStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Stack size: %d\n", size(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    return 0;
}