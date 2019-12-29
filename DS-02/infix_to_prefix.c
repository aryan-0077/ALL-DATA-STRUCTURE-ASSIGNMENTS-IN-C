#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack is Full \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty \n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int pre(char x)
{
    if(x=='+'|| x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;

    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

char * reverse(char *s)
{
    char *r;
    int len = strlen(s);
    r = (char *)malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++)
    {
        r[len - i -1] = s[i];
    }
    r[len]='\0';
    return r;
}

char * InToPost(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+2)*sizeof(char));
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j]='\0';

    return postfix;
}


int main()
{
    char *infix = "a+b*c";
    push(' ');

    char *r = reverse(infix);
    char *postfix = InToPost(r);
    char *r1 = reverse(postfix);

    //printf("Reverse is %s\n",r);
    printf("infix is %s\n",infix);
    printf("Prefix is %s\n",r1);

    return 0;
}
