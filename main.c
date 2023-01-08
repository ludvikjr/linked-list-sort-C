#include <stdio.h>
#include <stdlib.h>

typedef struct TITEM
{
    struct TITEM *next;
    int data;
} TITEM;

TITEM *readInput(int *length, TITEM *head)
{
    *length = 0;

    int data;
    TITEM *temp = head;

    while (scanf("%d", &data) == 1)
    {
        if (*length == 0)
        {
            head->data = data;
            head->next = NULL;
            temp = head;
            (*length)++;
        }
        else
        {
            TITEM *newNode = (TITEM *)malloc(sizeof(TITEM));
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
            (*length)++;
        }
    }

    if (!(*length) || !feof(stdin))
    {
        return 0;
    }

    return head;
}

void printList(TITEM *head)
{
    TITEM *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(TITEM *l)
{
    while (l)
    {
        TITEM * temp = l->next;
        free(l);
        l = temp;
    }
}

int main()
{
    TITEM *head = (TITEM *)malloc(sizeof(TITEM));
    int length = 0;

    printf("Insert a sequence of numbers\n");

    head = readInput(&length, head);

    if (!head)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Choose sorting algorithm for a linked list\n");
    printf("1 - Bubble sort\n2 - Merge sort\n");

    freeList(head);
    return 0;
}
