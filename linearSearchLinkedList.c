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

void performLinearSearchLL(struct Node *head, int target)
{
    int index = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->value == target)
        {
            printf("Target found at index %d\n", index);
            return;
        }
        current = current->next;
        index++;
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

    performLinearSearchLL(head, target);

    return 0;
}

// Time Complexity :
//     Insertion : O(n)
//     Linear Search : O(n)

// Space Complexity :
// Linked List : O(n)
// Linear Search : O(1)