#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new Node(val);
}

int findMiddleOfLinkedList(Node *head)
{
    if (head == NULL)
        return -1;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

int main()
{

    Node *head = NULL;

    while (true)
    {
        int linkedListVal;
        cin >> linkedListVal;
        if (linkedListVal == -1)
            break;
        insertAtEnd(head, linkedListVal);
    }

    int middleOfLinkedList = findMiddleOfLinkedList(head);
    cout << middleOfLinkedList << endl;

    return 0;
}