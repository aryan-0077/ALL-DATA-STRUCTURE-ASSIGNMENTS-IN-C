#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("STACK IS FULL \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
