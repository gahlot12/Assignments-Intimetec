#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
} Stack;

void initializeStack(Stack *stack, int capacity)
{
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

typedef struct Queue
{
    Stack *stack1;
    Stack *stack2;
    int size;
} Queue;

void initializeQueue(Queue *queue, int capacity)
{
    queue->stack1 = (Stack *)malloc(sizeof(Stack));
    queue->stack2 = (Stack *)malloc(sizeof(Stack));
    initializeStack(queue->stack1, capacity);
    initializeStack(queue->stack2, capacity);
    queue->size = 0;
}

void enqueue(Queue *queue, int value)
{
    push(queue->stack1, value);
    queue->size++;
    printf("Enqueued %d to the queue\n", value);
}

int dequeue(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return -1;
    }

    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    queue->size--;
    return pop(queue->stack2);
}

int peek(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }

    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return peek(queue->stack2);
}

int isEmptyQueue(Queue *queue)
{
    return queue->size == 0;
}

int sizeQueue(Queue *queue)
{
    return queue->size;
}

int main()
{
    Queue queue;
    initializeQueue(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", sizeQueue(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", sizeQueue(&queue));

    return 0;
}
