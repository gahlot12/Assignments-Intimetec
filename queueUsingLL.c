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

// Enqueue Operation:
// The function enqueue() adds a new node with the given value to the rear of the queue.
// If the queue is empty, the new node becomes both the front and the rear of the queue.
// If the queue is not empty, the new node is added after the current rear, and the rear pointer is updated.
// Time Complexity: O(1)
void enqueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
    printf("Enqueued %d to the queue.\n", value);
}

// Dequeue Operation:
// The function dequeue() removes and returns the value of the front element.
// After removing the element, the front pointer is updated to the next node.
// If the queue becomes empty after this operation, the rear is also set to NULL.
// Time Complexity: O(1)
int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return -1;
    }

    int dequeuedValue = queue->front->data;

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);

    queue->size--;
    return dequeuedValue;
}

// Peek Operation:
// The function peek() simply returns the value of the front element without removing it from the queue.
// If the queue is empty, it returns -1 to indicate an error.
// Time Complexity: O(1)
int peek(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }

    return queue->front->data;
}

// Size Operation:
// The function size() returns the current number of elements in the queue.
// Time Complexity: O(1)
int size(Queue *queue)
{
    return queue->size;
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));

    printf("Queue size: %d\n", size(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", size(&queue));

    return 0;
}
