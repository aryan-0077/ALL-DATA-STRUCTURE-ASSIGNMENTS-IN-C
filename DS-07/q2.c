#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int coef;
	int exp;
	struct node *next;
};

struct node* insert_end(struct node * head , int x,int y)
{	
	struct node* p= (struct node*) malloc(sizeof(struct node));
	p->coef=x;
	p->exp=y;
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
	printf("Enter the no. of nodes you want to enter : \n");
	scanf("%d",&n);
	int x,y;
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the coef and exponent: \n");
		scanf("%d %d",&x,&y);
		head=insert_end(head, x,y);
		
	}
	return head;
	
}

struct node* add_polynomial(struct node *head1 , struct node* head2)
{	
	struct node *head3 =NULL;
	struct node* p=head1;
	struct node* q= head2;
	while(p!=NULL && q!=NULL)
	{
		if(p->exp > q->exp)
		{
			head3=insert_end(head3,p->coef, p->exp);
			p=p->next;
		}
		
		else if(p->exp < q->exp)
		{
			head3=insert_end(head3, q->coef, q->exp);
			q=q->next;
			
		}
		
		else 
		{
            head3=insert_end(head3,p->coef + q->coef, p->exp);
            p=p->next;	
            q=q->next;
		}
		
	}
	while(p!=NULL)
    {
	    head3=insert_end(head3, p->coef, p->exp);
	    p = p->next;
    }
    while(q!=NULL)
    {
        head3=insert_end(head3, q->coef, q->exp);
        q = q->next;
    }

return head3;

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
		printf("%d^%d  ", p->coef, p->exp);
		p=p->next;
		
	}

	printf("\n");
}
	



void main()
{	
		struct node *head1 =NULL;
		struct node *head2=NULL;
		int x,y;
	
	printf("Enter 1: To enter first polynomial\n");
	printf("Enter 2: To enter Second polynomial\n");
	printf("Enter 3: To add  polynomial \n");
	printf("Enter 4: To display \n");
	int n;
	
	char c='y';
	while(c=='y')
	{	printf("Enter your choice : \n");
		scanf("%d",&n);
	switch(n)
	{
		case 1: head1=create_list(head1);
				break;
				
		case 2: head2=create_list(head2);
				break;
				
		case 3: head1=add_polynomial(head1,head2);
				break;

		case 4: display(head1);
				break;

	
	}
	printf("Want to continue (y/n) : \n");
	scanf("%c",&c);
	scanf("%c",&c);
	}
	
}