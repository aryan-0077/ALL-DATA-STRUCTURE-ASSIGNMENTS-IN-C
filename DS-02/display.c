#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ",p->data);
         p = p->next;
    }
    printf("\n");
}
