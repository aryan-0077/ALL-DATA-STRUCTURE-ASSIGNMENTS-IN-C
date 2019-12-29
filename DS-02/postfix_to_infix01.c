#include <stdio.h>
#include <stdlib.h>
int top = 10;
struct node
{
	char ch;
	struct node *next;
	struct node *prev;
}  *stc[11];
typedef struct node node;

void push(node *str)
{
	if (top <= 0)
	printf("stc is Full ");
	else
	{
		stc[top] = str;
		top--;
	}
}

node *pop()
{
	node *p;
	if (top >= 10)
		printf("stc is Empty ");
	else
		p = stc[++top];
	return p;
}
void convert(char p[])
{
	node *op1,  *op2;
	node *tmp;
	int i;
	for (i=0;p[i]!='\0';i++)
	if (p[i] >= 'a'&& p[i] <= 'z'|| p[i] >= 'A' && p[i] <= 'Z')
	{
		tmp = (node*)malloc(sizeof(node));
		tmp->ch = p[i];
		tmp->next = NULL;
		tmp->prev = NULL;
		push(tmp);
	}
	else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' ||
p[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		tmp = (node*)malloc(sizeof(node));
		tmp->ch = p[i];
		tmp->next = op1;
		tmp->prev = op2;
		push(tmp);
	}
}

void display(node *tmp)
{
	if (tmp != NULL)
	{
		display(tmp->prev);
		printf("%c", tmp->ch);
		display(tmp->next);
	}
}

int main()
{
	char p[50];
	printf("Enter the postfix pression :");
	scanf("%s", p);
	convert(p);
	printf("\nThe Equivalant Infix pression is:");
	display(pop());
	printf("\n\n");
}
