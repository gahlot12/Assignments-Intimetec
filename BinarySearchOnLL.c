// Implement a linear search on a singly linked list to find the index of the first occurrence of a target value. If the target is found, return its index, otherwise, print "Target not found".

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

void insertNodeAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node *getNodeAtIndex(struct Node *head, int index)
{
    struct Node *current = head;
    for (int i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }
    return current;
}

void performBinarySearchLL(struct Node *head, int target, int length)
{
    int left = 0, right = length - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        struct Node *midNode = getNodeAtIndex(head, mid);

        if (midNode == NULL)
        {
            printf("Target not found\n");
            return;
        }

        if (midNode->value == target)
        {
            printf("Target present at index %d\n", mid);
            return;
        }
        else if (midNode->value < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Target not found\n");
}

int main()
{
    struct Node *head = NULL;

    int target;
    scanf("%d", &target);

    int size = 0;
    while (1)
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
            break;
        size++;
        insertNodeAtEnd(&head, value);
    }

    performBinarySearchLL(head, target, size);

    return 0;
}

// Time Complexity :
//     Insertion : O(n)
//     Binary Search : O(n*log(n))
//      Finding the middle node in each step requires O(n) time.
//      In each step we are reducing the size by n/2 so we perform O(log n) steps.

// Space Complexity :
// Linked List : O(n)
// Binary Search : O(1)