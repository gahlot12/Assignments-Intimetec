#include <stdio.h>
#include <stdlib.h>

// Node Structure:
// A Node contains an integer data and a pointer next that points to the next node in the linked list.
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue Structure:
// The Queue structure has:
// front: A pointer to the first node in the queue.
// rear: A pointer to the last node in the queue.
// size: An integer that tracks the number of elements in the queue.
typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

// Queue Initialization:
// The function initializeQueue() sets both front and rear to NULL and the size to 0.
void initializeQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// isEmpty Operation:
// Checks if the queue is empty by checking if the size is 0.
int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

// Enqueue Operation:
// The function enqueue() adds a new node with the given value to the rear of the queue.
// If the queue is empty, it sets both front and rear to the new node.
// Otherwise, it adds the new node at the rear and updates the rear pointer.
void enqueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Dequeue Operation:
// The function dequeue() removes and returns the value of the front element.
// After removing the element, it updates the front pointer to the next node.
// If the queue becomes empty after this operation, it sets the rear pointer to NULL.
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return -1;
    }
    Node *temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;

    // If the queue becomes empty after the dequeue, set rear to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return dequeuedValue;
}

// Peek Operation:
// The function peek() returns the value of the front element without removing it from the queue.
// If the queue is empty, it returns -1 to indicate an error.
int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }
    return queue->front->data;
}

// Stack Structure:
// The stack is implemented using a single queue.
// The stack structure has a pointer to the queue.
typedef struct Stack
{
    Queue *queue;
} Stack;

// Stack Initialization:
// The function initializeStack() initializes the stack by creating a new queue and setting its front and rear to NULL, with size 0.
void initializeStack(Stack *stack)
{
    stack->queue = (Queue *)malloc(sizeof(Queue));
    initializeQueue(stack->queue);
}

// Push Operation:
// The function push() adds an element to the stack by enqueuing it into the queue.
// After enqueuing the new element, the queue is rotated such that the newly pushed element becomes the front of the queue.
// This ensures the stack's top element is at the front of the queue.
// Time complexity : O(N)
void push(Stack *stack, int value)
{
    enqueue(stack->queue, value);
    int size = stack->queue->size;

    for (int i = 0; i < size - 1; i++)
    {
        int frontValue = dequeue(stack->queue);
        enqueue(stack->queue, frontValue);
    }
    printf("Pushed %d to the stack.\n", value);
}

// Pop Operation:
// The function pop() removes and returns the front element of the queue, which is the top element of the stack.
// It simply dequeues the front element of the queue.
int pop(Stack *stack)
{
    if (isEmpty(stack->queue))
    {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    }
    return dequeue(stack->queue);
}

// Peek Operation:
// The function peek() returns the value of the front element in the queue without removing it.
// This represents the top element of the stack.
int peek(Stack *stack)
{
    if (isEmpty(stack->queue))
    {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return peek(stack->queue);
}

// Size Operation:
// The size of the stack is directly tracked by the size of the queue.
// We simply return the size of the queue.
int size(Stack *stack)
{
    return stack->queue->size;
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
    printf("Stack size: %d\n", size(&stack));

    return 0;
}
