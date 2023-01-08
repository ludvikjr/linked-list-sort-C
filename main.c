#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE
{
    int data;
    TNODE *next;
} TNODE;

int readInput(int *length, TNODE *head)
{
    *length = 0;

    int data;
    TNODE *temp = NULL;

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
        }
    }

    if (!(*length) || !feof(stdin))
    {
        return 0;
    }

    return 1;
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

void freeTree(TNODE *head)
{
    TNODE *temp = head->next;
    while (head)
    {
        free(head);
        head = temp;
        temp = head->next;
    }
}

int main()
{

    printf("Choose sorting algorithm for a linked list");
}
