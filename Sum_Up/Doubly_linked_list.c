#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node * prev;
	int info;
	struct node *next;
};

struct node* insert_start(struct node* head, int x)
{
	struct node * p= (struct node*)malloc(sizeof(struct node));
	p->info=x;
	
	if(head==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		head=p;
		return head;
		
	}
	
	p->next=head;
	head->prev=p;
	p->prev=NULL;
	head=p;
	return head;
	
}

struct node* insert_end(struct node* head, int x){
	
	struct node* p= (struct node* ) malloc(sizeof(struct node));
	p->info=x;
	if(head==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		head =p;
		return head;
	}
	
	struct node *q = head;
	while(q->next!=NULL)
	{
		q=q->next;
		
	}
	
	p->prev= q;
	p->next=NULL;
	q->next=p;
	return head;
	
	
}

struct node* insert_before_value(struct node* head, int x, int n)
{
	if(head==NULL)
	{
		printf("List is empty.");
		return head;
	}
	
	struct node* p= (struct node*) malloc( sizeof(struct node));
	p->info=x;
	
	struct node* q= head;
	
	if(q->info==n)
	{
		head= insert_start(head,x);
		return head;
	}
	
	q=head->next;
	while(q->info!=n)
	{
		q=q->next;
		
	}
	
	p->prev=q->prev;
	p->next= q;
	
	q->prev->next=p;
	q->prev=p;
	return head;
	
	
}

struct node* insert_after_value(struct node* head,int x, int n)
{
	struct node* p= (struct node*) malloc( sizeof(struct node));
	
	if(head==NULL)
	{
		printf ("List is empty.");
		return head;
		
	}
	
	p->info=x;
	
	struct node* q= head;
	
	while(q->info!=n)
	{
		q=q->next;
		
	}
	
	p->next=q->next;
	p->prev=q;
	q->next->prev=p;
	q->next=p;
	return head;	
}

struct node* delete_first(struct node* head)
{
	if(head==NULL)
	{
		printf("List is empty.");
		return head;
	}
	
	struct node* q= head;
	head=q->next;
	free(q);
	return head;
	
}

struct node* delete_last(struct node* head)
{
	if(head==NULL)
	{
		printf ("List is empty");
		return head;
	}
	
	struct node* q= head;
	
	if(q->next==NULL)
	{
		head= NULL;
		free(q);
		return head;
		
	}
	
	while(q->next!=NULL)
	{
		q=q->next;
	}
	
	q->prev->next=NULL;
	
	free(q);
	return head;
	
	
}

struct node* delete_at_value(struct node* head, int n)
{
	if(head==NULL)
	{
		printf("List is empty.");
		return head;
	}
	
	if(head->info==n)
	{
		head= delete_first(head);
		return head;
	}
	
	struct node* q= head->next;
	
	while(q->info!=n)
	{
		q=q->next;
	}
	
	if(q->next!=NULL)
	{
		q->prev->next=q->next;
		q->next->prev=q->prev;
		free(q);
		return head;
		
	}
	
	q->prev->next=NULL;
	
	free(q);
	
	return head;
	
}







struct node* create_list(struct node* head)
{
	int n;
	head=NULL;
	printf("Enter the no. of nodes , you want to enter : ");
	scanf("%d",&n);
	int x;
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the info : ");
		scanf("%d",&x);
		head=insert_end(head, x);
		
	}
	return head;
	
}


		
void display(struct node* head)
{
	struct node* p=head;
	
	
	if(head == NULL)
	{
		printf("list is empty.");
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
	
	printf("Enter 1: To create list");
	printf("\nEnter 2: Insert an element at start of the list");
	printf("\nEnter 3: Insert an element at the end of list");
	printf(	"\nEnter 4: Insert an element before an existing element ");
	printf(	"\nEnter 5: Insert an element after an existing element");
	printf(	"\nEnter 6: Delete first element of the linked list");
	printf(	"\nEnter 7: Delete the last element of the linked list");
	printf(	"\nEnter 8: Delete an element whose info is x in a linked list");
	printf(	"\nEnter 9: Display the content of linked list\n");
			
			
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : ");
		scanf("%d",&n);
	switch(n)
	{
	case 1: head=create_list(head);
				break;
				
		case 2: printf("Enter the info to insert at start: ");
				scanf("%d",&x);
				head=insert_start(head,x);
				break;
				
		case 3: printf("Enter the info to insert at end : ");
				scanf("%d",&x);
				head= insert_end(head,x);
				break;
				
		case 4:  printf("Enter the info and value before which you want to insert : ");
				scanf("%d %d",&x,&y);
				head=insert_before_value(head,x,y);
				break;
		
		case 5:  printf("Enter the info and value after which you want to insert  : ");
				scanf("%d %d",&x,&y);
				head=insert_after_value(head,x,y);
				break;
				
		case 6:head=delete_first(head);
				break;
				
		case 7:head=delete_last(head);
				break;
				
		case 8:	printf("Enter the value to delete : ");
				scanf("%d",&x);
				head=delete_at_value(head,x);
				break;
		
		case 9: display(head);
				 break;
	}
	printf("Want to continue (y/n) : ");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}
				
				
				
				
