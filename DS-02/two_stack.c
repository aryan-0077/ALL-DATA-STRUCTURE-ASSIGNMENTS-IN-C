#include<stdio.h>
#include<stdlib.h>

void pushs1(int arr[], int x, int *top1, int *top2)
{
	if (*top1 < (*top2 - 1))
	{
		(*top1)++;
		arr[*top1] = x;
	}
	else
	{
		printf("Stack Overflow\n");
		exit(1);
	}
}

void pushs2(int arr[], int x, int *top1, int *top2)
{
	if (*top1 < (*top2 - 1))
	{
		(*top2)--;
		arr[*top2] = x;
	}
	else
	{
		printf("Stack Underflow\n");
		exit(1);
	}
}

int pops1(int arr[], int *top1, int *top2)
{
	if (*top1 >= 0 )
	{
		int x = arr[*top1];
		(*top1)--;
		return x;
	}
	else
	{
		printf("Stack Underflow\n");
		exit(1);
	}
}
int pops2(int arr[], int n, int *top1, int *top2)
{
	if (*top2 < n)
	{
		int x = arr[*top2];
		(*top2)++;
		return x;
	}
	else
	{
		printf("Stack Overflow\n");
		exit(1);
	}
}

int main()
{
	int top1, top2;
	int n, a, b, x;
	printf("Enter the size of the array :- ");
	scanf("%d",&n);
	top1 = -1, top2 = n;
	int arr[n];
	printf("Enter the no. of elements to be pushed in stack 1 and 2 :- ");
	scanf("%d%d",&a,&b);
	printf("Enter the elements in the stacks\n");
	for(x = 0; x < a; x++)
	{
		int m;
		scanf("%d",&m);
		pushs1(arr, m, &top1, &top2);
	}
	for(x = 0; x < b; x++)
	{
		int m;
		scanf("%d",&m);
		pushs2(arr, m, &top1, &top2);
	}
	int x1 = pops1(arr,  &top1, &top2);
	int x2 = pops2(arr, n,  &top1, &top2);
	int x3 = pops2(arr, n,  &top1, &top2);
	printf("Popped element from stack 1 is %d\n",x1);
	printf("Popped element from stack 2 is %d\n",x2);
	printf("Popped element from stack 2 is %d\n",x3);
	return 0;
}
