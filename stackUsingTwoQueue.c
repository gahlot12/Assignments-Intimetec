#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

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

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return dequeuedValue;
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }
    return queue->front->data;
}

typedef struct Stack
{
    Queue *q1;
    Queue *q2;
} Stack;

void initializeStack(Stack *stack)
{
    stack->q1 = (Queue *)malloc(sizeof(Queue));
    stack->q2 = (Queue *)malloc(sizeof(Queue));
    initializeQueue(stack->q1);
    initializeQueue(stack->q2);
}

// When a new element is pushed onto the stack, we will enqueue it to q2.
// After that, we will move all elements from q1 to q2 so that the newest element in q2 is always at the front.
// Finally, we swap the names of q1 and q2
// Therefore the Time Complexity of the push operation is O(n).
void push(Stack *stack, int value)
{
    enqueue(stack->q2, value);

    while (!isEmpty(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    printf("Pushed %d to the stack.\n", value);
}

// The pop operation will dequeue the front element from q1, as the front of q1 will always represent the top of the stack.
int pop(Stack *stack)
{
    if (isEmpty(stack->q1))
    {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    }
    return dequeue(stack->q1);
}

int peek(Stack *stack)
{
    if (isEmpty(stack->q1))
    {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return peek(stack->q1);
}

int size(Stack *stack)
{
    return stack->q1->size;
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
