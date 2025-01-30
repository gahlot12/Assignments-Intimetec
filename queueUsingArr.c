// Brief overview of the implementation:
// 1. Queue Structure
//     First I have declare an array with size MAX that holds the element to the Queue
//     It has "front" which points to the front element of the Queue
//     It has "rear" which points to the rear element of the Queue
//     It has "size" which shows the current size of the queue

// 2. Made a function to initialize the queue

// 3. Made a function to check if the queue is empty or not. To do this we check directly the size of the queue if it is 0 we return it's empty otherwise not

// 4. Made a function to check if the queue is full. To check this we can check if the size is equal to MAX then return it's full otherwise not

// 5. Made an enqueue function which adds an element to the queue. It checks if the queue is full before adding the element. The rear index is updated in a circular manner, i.e., it wraps around when it reaches the end of the array.

// 6. Made a dequeu function which removes the front element from the queue and returns it. It checks if the queue is empty before attempting to dequeue. The front index is updated in a circular manner. If only one element was in the queue, both front and rear are reset to -1.

// 7. Function peek returns the front element of the queue without removing it. If the queue is empty, it returns -1 to indicate an error.

// Time Complexity:
// All operations (enqueue, dequeue, peek, isEmpty, and size) have a time complexity of O(1).

// Space Complexity:
// The space complexity is O(MAX), where MAX is the maximum number of elements the queue can hold, since the queue uses an array of fixed size MAX.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *queue)
{
    queue->arr = (int *)malloc(MAX * sizeof(int));
    if (queue->arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

int isFull(Queue *queue)
{
    return queue->size == MAX;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }

    if (queue->rear == -1)
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("Enqueued %d to the queue.\n", value);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return -1;
    }

    int dequeuedValue = queue->arr[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX;
    }

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

    return queue->arr[queue->front];
}

int size(Queue *queue)
{
    return queue->size;
}

void freeQueue(Queue *queue)
{
    free(queue->arr);
}

int main()
{
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", size(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", size(&queue));

    freeQueue(&queue);

    return 0;
}
