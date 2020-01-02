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

struct node* concatinate(struct node *head1, struct node *head2)
{
	struct node *p = head1;
	
	if(head1 == NULL)
		return head2;
	
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	p->next = head2;
	return head1;
}

int main()
{
	struct node *head1 =NULL,*head2 = NULL;
	head1 = create_list(head1);
	head2 = create_list(head2);
	
	head1 = concatinate(head1,head2);
	printf("Now the elements of Combined LL is : ");
	display(head1);
	
	return 0;	
}
