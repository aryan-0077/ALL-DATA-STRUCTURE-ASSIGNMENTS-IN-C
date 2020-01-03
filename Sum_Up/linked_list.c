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

struct node* insert_end(struct node * head , int x)
{	
	struct node* p= (struct node*) malloc(sizeof(struct node));
	p->info=x;
	struct node* tmp; 
	
	// no node exits 
	if(head==NULL)
	{
		p->next= NULL;
		return p;
	}
	
	// tmp points to head and then goes to last node 
	tmp= head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	
	}
	tmp->next=p;
	p->next=NULL;
	
	return head;
}


// We let  that the value exists.
struct node* insert_after_value(struct node* head , int x, int n)
{
	struct node* p= (struct node*) malloc(sizeof(struct node));
	p->info=x;
	
	struct node* tmp = head;
	
	while(tmp->info!=n)
	{
		tmp=tmp->next;
	}
	
	p->next=tmp->next;
	tmp->next=p;
	
	return head;
	
}

struct node* insert_before_value(struct node* head , int x, int n)
{
	struct node* p= (struct node*) malloc(sizeof(struct node));
	p->info=x;
	
	// if the element to insert before is head
	if(head->info==n)
	{	p->next=head;
		head = p;
		return head;
	}
	
	// pointer which points on head
	struct node* tmp = head;
	
	while((tmp->next)->info != n)
	{
		tmp=tmp->next;
	}
	
	p->next=tmp->next;
	tmp->next=p;
	
	return head;
	
}

struct node* delete_first(struct node *head)
{
	struct node* p= head;
	if(head==NULL)
		printf("List is empty.");
		
	else
	{head=p->next;
	free(p);}
	
	return head;
	
	
}

struct node* delete_last(struct node *head)
{
	
	struct node *p= head;
	if(p == NULL)
	{
		printf("List is Empty ");
	}
	
	if(p->next == NULL)
	{
		head=NULL;
		return head;
	}
	
	
	while((p->next)->next != NULL)
	{
		p=p->next;
	}
	
	free(p->next);
	//p->next=NULL;
	
	return head;
	
}

struct node* delete_at_value(struct node* head, int n)
{
	struct node *tmp,*p;
	
	if(head==NULL)
	{
		printf("List is empty");
		return head;
	}
	
	if(head->info == n)
	{
		tmp= head;
		head= head->next;
		free(tmp);
		return head;
	}
	
	p=head;
	
	while(p->next != NULL)
	{
		
		if((p->next)->info == n)
		{
			tmp= p->next;
			p->next= tmp->next;
			free(tmp);
			return head;
		}
		p=p->next;
	}
	
	printf("Element not found .");
	
	return head;
}

// Creating the List First Time . 
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
				
		case 2: printf("Enter the info to insert : ");
				scanf("%d",&x);
				head=insert_start(head,x);
				break;
				
		case 3: printf("Enter the info to insert at end : ");
				scanf("%d",&x);
				head= insert_end(head,x);
				break;
				
		case 4:  printf("Enter the info and vale to insert : ");
				scanf("%d %d",&x,&y);
				head=insert_before_value(head,x,y);
				break;
		
		case 5:  printf("Enter the info and value to insert : ");
				scanf("%d %d",&x,&y);
				head=insert_after_value(head,x,y);
				break;
				
		case 6:head=delete_first(head);
				break;
				
		case 7:head=delete_last(head);
				break;
				
		case 8:	printf("Enter the value : ");
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
				
				
				
				
