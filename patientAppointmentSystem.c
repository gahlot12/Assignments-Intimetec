// Patient Appointment System – Sorting by Severity Level (Custom Order Sorting) Scenario:
// A hospital appointment system needs to manage patient check-ins based on severity levels. Each patient is assigned a severity category instead of a numerical priority:
// • Critical (Highest Priority)
// • Serious (Medium Priority)
// • Stable (Lowest Priority)

// The system must process patients with the highest severity first, but if two patients have the same severity level, the earlier registered patient should be processed first (FIFO for the same severity). You need to implement a linked list-based system that sorts patients by severity using a custom order sorting approach.

// Input Format: • The first line contains an integer n, the number of patients. • Each of the next n lines contains:
// o patient_id(Unique ID for the patient)
// o severity (One of "Critical", "Serious", or "Stable")
// Output Format: Print the sorted list of patients based on severity priority order.
// Sample - Input 5 101 Serious 102 Critical 103 Stable 104 Serious 105 Critical
// Output
// 102 Critical 105 Critical 101 Serious 104 Serious 103 Stable

#include <stdio.h>
#include <stdlib.h>

typedef struct Patient
{
    int patient_id;
    char severity[10];
    struct Patient *next;
} Patient;

void copySeverity(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int compareSeverity(char *s1)
{
    char critical[] = "Critical";
    char serious[] = "Serious";

    int i = 0;

    while (s1[i] == critical[i] && s1[i] != '\0' && critical[i] != '\0')
    {
        i++;
    }
    if (s1[i] == '\0' && critical[i] == '\0')
    {
        return 1;
    }

    i = 0;

    while (s1[i] == serious[i] && s1[i] != '\0' && serious[i] != '\0')
    {
        i++;
    }
    if (s1[i] == '\0' && serious[i] == '\0')
    {
        return 2;
    }

    return 0;
}

void insertPatient(Patient **head, int id, char *severity)
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->patient_id = id;
    copySeverity(newPatient->severity, severity);
    newPatient->next = NULL;

    if (*head == NULL)
    {
        newPatient->next = (*head);
        *head = newPatient;
        return;
    }

    Patient *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    newPatient->next = current->next;
    current->next = newPatient;
}

void sortPatients(Patient **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    Patient *current;

    Patient *last = NULL;

    int swapped;

    while (current->next != NULL)
    {
        swapped = 0;
        current = *head;
        while (current->next != last)
        {
            if (compareSeverity(current->severity) > compareSeverity(current->next->severity))
            {
                int temp_id = current->patient_id;
                char temp_severity[10];
                copySeverity(temp_severity, current->severity);

                current->patient_id = current->next->patient_id;
                copySeverity(current->severity, current->next->severity);

                current->next->patient_id = temp_id;
                copySeverity(current->next->severity, temp_severity);

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
        if (swapped == 0)
            break;
    }
}

void printPatients(Patient *head)
{
    while (head != NULL)
    {
        printf("%d %s\n", head->patient_id, head->severity);
        head = head->next;
    }
}

void freeList(Patient *head)
{
    while (head != NULL)
    {
        Patient *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int numberOfPatients;
    scanf("%d", &numberOfPatients);

    int id;
    char severity[10];

    Patient *head = NULL;

    for (int i = 0; i < numberOfPatients; i++)
    {
        scanf("%d %s", &id, severity);
        insertPatient(&head, id, severity);
    }

    sortPatients(&head);

    printPatients(head);

    freeList(head);

    return 0;
}