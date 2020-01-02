#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *next;
};



struct node* insert_start(struct node* head, int x)
{
	struct node *p= (struct node*) malloc(sizeof(struct node));
	p->info=x;
	p->next= head;
	head =p;
	
	return head;
	
}



struct node* delete_first(struct node *head)
{
	struct node* p= head;
	if(head==NULL)
		printf("Stack is empty.\n");
		
	else
	{
	  printf("Poped element : %d\n",p->info);	
	 head=p->next;
	 free(p);}
	
	return head;
	
	
}



void display(struct node* head)
{
	struct node* p=head;
	
	
	if(head == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	while(p!=NULL)
	{
		printf("%d ", p->info);
		p=p->next;
		
	}
}
	
	





void main()
{	
		struct node *head =NULL;
		int x,y;
	
	printf("Enter 1: To push element\n");
	printf("Enter 2: To pop element\n");
	printf("Enter 3: To display element \n");
	
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : \n");
		scanf("%d",&n);
	switch(n)
	{
		case 1: printf("Enter the  element to push : \n");
				scanf("%d",&x);
				
				head=insert_start(head,x );
				break;
				
		case 2:head=delete_first(head);
				break;
		
		case 3: display(head);
				break;
	}
	printf("Want to continue (y/n) : \n");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}