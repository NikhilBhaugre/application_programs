#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));         // 1

    newn->data = no;                            // 2
    newn->next = NULL;

    if(*Head == NULL)                           // 3
    {
        *Head = newn;                           // 4
    }
    else
    {
        newn->next = *Head;                     // 5
        *Head = newn;                           // 6
    }
}

void DisplayI(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\t",Head->data);
        Head=Head->next;
    }
}

void DisplayR(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\t",Head->data);
        Head=Head->next;
        DisplayR(Head);
    }
}

int main()
{
    PNODE First = NULL;

    Insert(&First,50);
    Insert(&First,40);
    Insert(&First,30);
    Insert(&First,20);
    Insert(&First,10);

    DisplayI(First);
    DisplayR(First);

    return 0;
}