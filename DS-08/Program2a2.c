#include<stdio.h>
#include<stdlib.h>
#define R 5
#define C 5
struct node
{
	int data,row,col;
	struct node *nextRow,*nextCol;
};
struct node* newNode(int data,int row,int col)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->row = row;
	temp->col = col;
	temp->nextRow = temp->nextCol = NULL;
	return temp;
}
struct node* above(struct node* multiList,int r,int c)
{
	struct node* n = multiList->nextCol;
	while(n->col!=c)
	{
		//printf("a %d\n",n->col);
		n = n->nextCol;
	}
	struct node* m =n;
	while(n->nextRow!=m && n->row<r)
	{
		//printf("b %d\n",n->row);
		n = n->nextRow;
	}
	return n;
}
struct node* left(struct node* multiList,int r,int c)
{
	struct node* n = multiList->nextRow;
	while(n->row!=r)
	{
		//printf("a %d\n",n->row);
		n = n->nextRow;
	}
	struct node* m=n;
	while(n->nextCol!=m && n->col<c)
	{
		n = n->nextCol;
	}
	return n;
}
void insert(struct node* multiList,int r,int c,int val)
{
	struct node* temp = newNode(val,r,c);
	struct node* above_row = above(multiList,r,c);
	struct node* left_col = left(multiList,r,c);
	temp->nextRow = above_row->nextRow;
	above_row->nextRow = temp;
	temp->nextCol = left_col->nextCol;
	left_col->nextCol = temp;
}
void display(struct node* multiList)
{
	struct node* n = multiList->nextRow;
	while(n!=multiList)
	{
		struct node* n1 = n->nextCol;
		while(n1!=n)
		{
			printf("%d\t%d\t%d\n",n1->row,n1->col,n1->data);
			n1 = n1->nextCol;
		}
		n = n->nextRow;
	}
}
void delete(struct node* multiList,int row)
{
	struct node* n = multiList->nextRow;
	while(n->row!=row)
	{
		n = n->nextRow;
	}
	struct node* m = n->nextCol;
	while(m!=n)
	{
		struct node* temp = m;
		struct node* a = above(multiList,m->row,m->col);
		struct node* l = left(multiList,m->row,m->col);
		a->nextRow = m->nextRow;
		l->nextCol = m->nextCol;
		m = m->nextCol;
		free(temp);
	}
	n->nextCol = n;
}
int main()
{
	struct node* multiList = newNode(-1,-1,-1);
	struct node* n = multiList;
	for(int i=0;i<R;i++)
	{
		struct node* temp = newNode(-1,i,-1);
		temp->nextCol = temp;
		n->nextRow = temp;
		n = n->nextRow;
	}
	n->nextRow = multiList;
	n = multiList;
	for(int i=0;i<C;i++)
	{
		struct node* temp = newNode(-1,-1,i);
		temp->nextRow = temp;
		n->nextCol = temp;
		n = n->nextCol;
	}
	n->nextCol = multiList;
	while(1)
	{
		printf("Press 1 for new element\nPress 2 for display\nPress 3 for deleting row\nPress 4 for exit\n");
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter row column and value: ");
			int r,c,val;
			scanf("%d%d%d",&r,&c,&val);
			insert(multiList,r,c,val);
		}
		else if(t==2)
		{
			display(multiList);
		}
		else if(t==3)
		{
			printf("Enter row you want to delete: ");
			int row;
			scanf("%d",&row);
			delete(multiList,row);
		}
		else
			break;
	}
}