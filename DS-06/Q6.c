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

struct node* reverse(struct node* head)
{

		struct node* p=head;
		struct node *prev=NULL;
		struct node *fd=NULL;

		while(p!=NULL)
		{	
			fd=p->next;
			p->next=prev;
			prev=p;
			p=fd;
			
		}

	return prev;
	
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

	printf("\n");
}
	



void main()
{	
		struct node *head =NULL;
		
		int x,y;
	
	printf("Enter 1: To create First list");
	printf("\nEnter 2: To reverse");
	printf("\nEnter 3: To display ");		
	
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : ");
		scanf("%d",&n);
	switch(n)
	{
		case 1: head=create_list(head);
				break;
	
		case 2: head=reverse(head);
				break;

		case 3: display(head);
				break;

	
	}
	printf("Want to continue (y/n) : ");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}
