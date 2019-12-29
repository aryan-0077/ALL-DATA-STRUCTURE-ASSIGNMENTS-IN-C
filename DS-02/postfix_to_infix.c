#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node
{
    char data[20];
    struct Node *next;
}*top=NULL;

void push(char x[])
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack is Full \n");
    else
    {
        strcpy(t->data ,x);
        t->next = top;
        top = t;
    }
}


char * pop()
{
    struct Node *t;
    char x[20];
    if(top==NULL)
        printf("Stack is Empty \n");
    else
    {
        t = top;
        top = top->next;
        strcpy(x , t->data);
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

// passing argument makes pointer from integer without a cast


char * PostToIn(char * postfix)
{
    char *infix;
    int len = strlen(postfix);
    infix = (char *)malloc((len+2)*sizeof(char));
    int i=0,j=0;
    while(postfix[i] != 0)
    {
        if(isOperand(postfix[i]))
            push(postfix[i++]);
        else
        {
            char s1[len+2],s2[len+2],s3[len+2];
            strcpy(s2,pop());
            strcpy(s1,pop());
            strcat(s1,postfix[i++]);
            strcat(s1,s2);
            push(s1);
        }
    }

    while(top != NULL)
    {
        infix[j++] = pop();
    }
    infix[j]='\0';
}


int main()
{
    // IT HAS WARNING AND NO OUTPUT

    char *postfix = "abc*+";
    push(' ');

    //char *r = reverse(infix);
    char *infix = PostToIn(postfix);
    //char *r1 = reverse(postfix);

    //printf("Reverse is %s\n",r);
    printf("Postfix is %s\n",postfix);
    printf("Infix is %s\n",infix);

    return 0;
}
