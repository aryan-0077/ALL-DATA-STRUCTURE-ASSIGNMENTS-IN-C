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


struct node* concat(struct node* head1, struct node* head2)
{
		struct node *q=head1;

		while(q->next!=NULL)
		q=q->next;

		q->next=head2;
		
		return head1;
	

}


struct node* merge(struct node* head1, struct node* head2)
{
		struct node *p=head1;
		struct node *head3=NULL;
		struct node *q=head2;

		while(q!=NULL && p!=NULL)
		{
			if(p->info < q->info)
			{
				head3=insert_end(head3,p->info);
				p=p->next;

			}

			else
			{
				head3=insert_end(head3,q->info);
				q=q->next;

			}
		
		}	

		
		while(p!=NULL)
			{	head3=insert_end(head3,p->info);
				p=p->next;
			}

		while(q!=NULL)
			{	head3=insert_end(head3,q->info);
				q=q->next;
			}

	return head3;
	
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
		struct node *head1 =NULL;
		struct node *head2=NULL;
	struct node *head3=NULL;
		int x,y;
	
	printf("Enter 1: To create First list");
	printf("\nEnter 2: To create Second list");
	printf("\nEnter 3: To merge both list");		
	printf("\nEnter 4: To display concatenated list\n");			
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : ");
		scanf("%d",&n);
	switch(n)
	{
		case 1: head1=create_list(head1);
				break;
				
		case 2: head2=create_list(head2);
				break;
				
		case 3: head3=merge(head1,head2);
				break;

		case 4: display(head3);
				break;

	
	}
	printf("Want to continue (y/n) : ");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}
