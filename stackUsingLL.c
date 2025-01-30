// Stack Structure:

// Node Structure: Each element of the stack is stored in a Node structure. Each node contains:
//      data: The actual data value of the node (in this case, an integer).
//      next: A pointer to the next node in the stack (if any). This forms the linked list structure.
// Stack Structure: The stack is represented by the Stack structure, which contains:
//      top: A pointer to the top node of the stack (the most recent element).
//      size: An integer to track the current size (number of elements) of the stack.

// Initialization of the Stack:
// The function initialiseStack() sets the stack's top pointer to NULL (indicating that the stack is initially empty) and the size to 0.

// Checking if the Stack is Empty:
//      The isEmpty() function checks whether the stack is empty by verifying if the top pointer is NULL.

// Push Operation:
//      The push() function creates a new node dynamically using malloc(), assigns the given value to the node's data field, and makes the node the new top of the stack by adjusting the top pointer. The new node points to the old top (if any).
//      The size of the stack is incremented, and a message is printed to indicate the pushed element.

// Pop Operation:
//      The pop() function removes and returns the top element of the stack. If the stack is empty, it prints an error message and returns -1. After popping, the top pointer is updated to point to the next node, and the memory of the old node is freed.
// The size of the stack is decremented.

// Peek Operation:
//      The peek() function returns the data of the top node without removing it from the stack. If the stack is empty, it prints an error message and returns -1.

// Size Operation:
//      The size() function simply returns the current size of the stack, which is tracked using the size variable.

// Memory Cleanup:
//      Since memory for each node is allocated dynamically, it’s important to free the memory of the node during the pop() operation. However, memory cleanup for the entire stack (like freeing all nodes) is not done here, but it can be added at the end of the program to avoid memory leaks.

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