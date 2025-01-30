// Stack Structure:

// Dynamic Array (arr): The stack elements are dynamically stored in an array using malloc. This allows the stack size to be flexible (up to MAX elements).
// top: This variable keeps track of the index of the top element of the stack. If the stack is empty, top is set to -1.
// Stack Initialization:

// A function initializeStack() is used to initialize the stack. It allocates memory for the stack's array and sets the top to -1 (indicating the stack is initially empty).
// Checking if the Stack is Empty or Full:

// isEmpty(): Returns 1 if the stack is empty (i.e., top == -1).
// isFull(): Returns 1 if the stack is full (i.e., top == MAX - 1).
// Push Operation:

// The push() function adds a new element to the stack. If the stack is full, it prints an error message. Otherwise, it increments the top index and stores the new element at that position in the array.
// Pop Operation:

// The pop() function removes and returns the top element from the stack. If the stack is empty, it prints an error message and returns -1. Otherwise, it decrements the top index.
// Peek Operation:

// The peek() function retrieves the top element without removing it. If the stack is empty, it returns -1 and prints an error message.
// Size Operation:

// The size() function returns the current number of elements in the stack, which is top + 1 because the top index is zero-based.
// Memory Cleanup:

// After performing the stack operations, free(stack.arr) is called to release the memory allocated for the stack’s array.

// Time Complexity:
// All operations (push, pop, peek, isEmpty, isFull, size) take O(1) time, making the stack highly efficient for typical operations.

// Space Complexity:
// The space complexity is O(MAX) because the stack uses a dynamically allocated array with a maximum size of MAX.

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
