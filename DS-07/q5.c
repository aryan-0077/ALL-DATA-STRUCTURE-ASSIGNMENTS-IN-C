#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *next;
};





struct node* insert_end(struct node * head , int x)
{	
	struct node* p= (struct node*) malloc(sizeof(struct node));
	p->info=x;
	struct node* tmp;
	if(head==NULL)
	{
		p->next= NULL;
		return p;
	}
	
	 tmp= head;
	
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	
	}
	tmp->next=p;
	p->next=NULL;
	
	return head;
}





struct node* delete_first(struct node *head)
{
	struct node* p= head;
	if(head==NULL)
		printf("List is empty\n");
		
	else
	{	  printf("Dequeued element : %d\n",p->info);	
		head=p->next;
	free(p);}
	
	return head;
	
	
}





		
void display(struct node* head)
{
	struct node* p=head;
	
	
	if(head == NULL)
	{
		printf("list is empty\n");
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
	
	printf("Enter 1: To enqueue element\n");
	printf("Enter 2: To dequeue element\n");
	printf("Enter 3: To display element \n");
	
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : \n");
		scanf("%d",&n);
	switch(n)
	{
		case 1: printf("Enter the  element to enqueue : \n");
				scanf("%d",&x);
				
				head=insert_end(head,x );
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