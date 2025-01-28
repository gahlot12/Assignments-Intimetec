// Detecting a Cycle in a Singly Linked List using Two Pointers

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

void createCycle(struct Node *head, int position)
{
    if (head == NULL)
        return;

    struct Node *cycleStartNode = NULL;
    struct Node *current = head;
    int index = 0;

    while (current->next != NULL)
    {
        if (index == position)
        {
            cycleStartNode = current;
        }
        current = current->next;
        index++;
    }

    if (cycleStartNode != NULL)
    {
        current->next = cycleStartNode;
    }
}

int hasCycle(struct Node *head)
{
    if (head == NULL)
        return 0;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct Node *head = NULL;

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int size = 0;
    printf("Enter the values for the linked list (end with -1):\n");
    while (1)
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
            break;
        size++;
        insertNodeAtEnd(&head, value);
    }

    printf("Enter the position (index) to create a cycle (-1 for no cycle): ");
    int cyclePosition;
    scanf("%d", &cyclePosition);

    if (cyclePosition != -1)
    {
        createCycle(head, cyclePosition);
    }

    if (hasCycle(head))
    {
        printf("Cycle detected in the linked list.\n");
    }
    else
    {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}

// Time Complexity :
//     Insertion : O(n)
//     Cycle Detection: O(n)

// Space Complexity :
// Linked List : O(n)
// Cycle Detection: O(1)