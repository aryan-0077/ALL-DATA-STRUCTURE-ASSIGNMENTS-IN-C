#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
    printf("Enter the no. of nodes , you want to enter : \n");
    scanf("%d",&n);
    int x;
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the info : \n");
        scanf("%d",&x);
        head=insert_end(head, x);

    }
    return head;

}

struct node* number_list (struct node* head)
{
    int n;
    head=NULL;

    printf("Enter the  number : \n");

    char o;
    scanf("%c",&o);
    char str[100];
    gets(str);
    int l = strlen(str);
    int q=0;

    int a[30];
    int count =1;
    int  k=0;
    int f;
    int g=0;
    for(int j=l-1;j>=0;j--)
    {
        if(g!=2)
            k = k+ (str[j]%48) * pow(10,g);

        if(g==2)
            k = k+ (str[j]%48) * 100;

        if(count%4==0 || j==0)
        {
            a[q]=k;
            q++;
            k=0;
            g=-1;
        }
        count++;
        g++;
    }


    int i;
    for(i=0;i<q;i++)
    {

        head=insert_end(head,a[i] );

    }
    return head;

}

struct node* add(struct node* head1 , struct node* head2)
{
    struct node *head3= NULL;
    struct node *p, *q;
    p=head1, q=head2;

    int sum , carry,c=0;

    while(p!=NULL && q!=NULL)
    {
        sum=(p->info + q->info)%10000;
        carry = (p->info + q->info)/10000;


        head3= insert_end(head3, sum+c);

        p=p->next;
        q=q->next;

        c=carry;
    }

    while(p!=NULL)
    {
        head3= insert_end(head3 , p->info+c);
        p=p->next;
        c=0;
    }

    while(q!=NULL)
    {
        head3= insert_end( head3 , q->info + c);
        q=q->next;
        c=0;
    }
    if(c==1)
        head3 = insert_end(head3 , c);

    return head3 ;
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
        printf("%d", p->info);
        p=p->next;

    }

    printf("\n");
}

void display_added(struct node* head3)
{
    struct node* p= head3;

    if(p==NULL)
        return ;

    display_added(p->next);
    printf("%d", p->info);


}




void main()
{
    struct node *head1 =NULL;
    struct node *head2=NULL , *head3=NULL;
    int x,y;



    printf("Enter 1: To enter first number \n");
    printf("Enter 2: To enter Second number \n");
    printf("Enter 3: To Add both number \n");
    printf("Enter 4: To display first number \n");
    printf("Enter 5: To display second number \n");
    printf("Enter 6: To display added number \n");
    int n;

    char c='y';
    while(c=='y')
    {	printf("Enter your choice : \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: head1=number_list(head1);
                break;

            case 2: head2=number_list(head2);
                break;

            case 3: head3=add(head1,head2);
                scanf("%c",&c);
                break;

            case 4: display(head1);
                scanf("%c",&c);
                break;

            case 5: display(head2);
                scanf("%c",&c);
                break;

            case 6: display_added(head3);

                printf("\n");
                scanf("%c",&c);
                break;




        }

        printf("Want to continue (y/n) : \n");

        scanf("%c",&c);
    }

}