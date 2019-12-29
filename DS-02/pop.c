#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

int pop
{
    struct Node *t;
    int x = -1;
    if(top == NULL)
    {
        printf("STACK IS EMPTY \n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
