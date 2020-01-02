#include<stdio.h>
#include<stdlib.h>

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

int length(struct node* head)
{
	if(head == NULL)
		return 0;
		
	return (1+length(head->next));
}

int main()
{
	struct node *head=NULL;
	
	printf("Enter some elements in Linked List : \n");
	head = create_list(head);
	
	printf("Length of linked List using Recursion is : %d",length(head));
	
	return 0;
}
