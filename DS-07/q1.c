
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


int length(struct node* q)
{
	if(q==NULL)
 		return 0;

	return 1+length(q->next) ;

}



struct node* second_first(struct node * head)
{
	int l= length(head);
	
	struct node *p, *q, *r ,*s;
	
	q= head;
	
	int count=1;
	while(q->next!=NULL)
	{
		if(count== l/2)
			p=q;
		
		count++;
		q=q->next;
		
	}
	
	r=p->next;
	
	q->next=head;
	
	p->next=NULL;
	
	return r;
	
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
	printf("\nEnter 2: To split in half and merge the second half as first .");
	printf("\nEnter 3: To display \n");		
	
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : ");
		scanf("%d",&n);
	switch(n)
	{
		case 1: head=create_list(head);
				break;
	
		case 2: head=second_first(head);
				break;

		case 3: display(head);
				break;

	
	}
	printf("Want to continue (y/n) : ");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}