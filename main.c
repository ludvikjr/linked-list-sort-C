#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    struct TNode *next;
    int data;
} TNODE;

TNODE *readInput(int *length, TNODE *head)
{
    *length = 0;

    int data;
    TNODE *temp = head;

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
            TNODE *newNode = (TNODE *)malloc(sizeof(TNODE));
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

void printTree(TNODE *head)
{
    TNODE *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeTree(TNODE *l)
{
    TNODE *head = l;
    TNODE *temp = head->next;
    while (head)
    {
        free(head);
        head = temp;
        temp = temp->next;
    }
}

int main()
{
    TNODE *head = (TNODE *)malloc(sizeof(TNODE));
    int length = 0;

    printf("Insert a sequence of numbers\n");

    head = readInput(&length, head);

    if (!head)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printTree(head);

    printf("Choose sorting algorithm for a linked list\n");
    printf("1 - Bubble sort\n2 - Merge sort\n");

    freeTree(head);
    return 0;
}
