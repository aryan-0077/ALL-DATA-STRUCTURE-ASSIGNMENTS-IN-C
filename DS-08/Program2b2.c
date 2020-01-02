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
void swap(struct node* multiList,int row1,int row2)
{
	struct node* p = multiList->nextRow;
	while(p->row!=row1)
	{
		p = p->nextRow;
	}
	struct node* q = multiList->nextRow;
	while(q->row!=row2)
	{
		q = q->nextRow;
	}
	struct node* i = p->nextCol;
	struct node* j = q->nextCol;
	//printf("a\n");
	while(i!=p && j!=q)
	{
		if(i->col==j->col)
		{
			int temp = i->data;
			i->data = j->data;
			j->data = temp;
			i = i->nextCol;
			j = j->nextCol;
		}
		else if(i->col<j->col)
		{
			insert(multiList,j->row,i->col,i->data);
			struct node* a = above(multiList,i->row,i->col);
			a->nextRow = i->nextRow;
			struct node* l = left(multiList,i->row,i->col);
			l->nextCol = i->nextCol;
			struct node* temp = i;
			i = i->nextCol;
			free(temp);
		}
		else
		{
			insert(multiList,i->row,j->col,j->data);
			struct node* a = above(multiList,j->row,j->col);
			a->nextRow = j->nextRow;
			struct node* l = left(multiList,j->row,j->col);
			l->nextCol = j->nextCol;
			struct node* temp = j;
			j = j->nextCol;
			free(temp);	
		}
	}
	//printf("b\n");
	while(j!=q)
	{
		//printf("as %d\n",j->data);
		insert(multiList,i->row,j->col,j->data);
		struct node* a = above(multiList,j->row,j->col);
		a->nextRow = j->nextRow;
		struct node* l = left(multiList,j->row,j->col);
		l->nextCol = j->nextCol;
		struct node* temp = j;
		j = j->nextCol;
		free(temp);	
	}
	//printf("c\n");
	while(i!=p)
	{
		insert(multiList,j->row,i->col,i->data);
		struct node* a = above(multiList,i->row,i->col);
		a->nextRow = i->nextRow;
		struct node* l = left(multiList,i->row,i->col);
		l->nextCol = i->nextCol;
		struct node* temp = i;
		i = i->nextCol;
		free(temp);
	}
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
		printf("Press 1 for new element\nPress 2 for display\nPress 3 for swapping\nPress 4 for exit\n");
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
			printf("Enter rows you want to swap: ");
			int row1,row2;
			scanf("%d%d",&row1,&row2);
			swap(multiList,row1,row2);
		}
		else
			break;
	}
}