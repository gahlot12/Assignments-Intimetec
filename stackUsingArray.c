#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
    int *arr;
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->arr = (int *)malloc(MAX * sizeof(int));
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is Full\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! No elements to pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int size(Stack *stack)
{
    return stack->top + 1;
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Stack size: %d\n", size(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    free(stack.arr);
    return 0;
}
