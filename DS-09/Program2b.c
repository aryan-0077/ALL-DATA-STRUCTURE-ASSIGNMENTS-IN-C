#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int search(int in[],int start,int end,int c)
{
	for(int i=start;i<=end;i++)
	{
		if(in[i]==c)
			return i;
	}
	return -1;
}
struct node* build_tree(int in[],int post[],int start,int end,int *postIndex)
{
	if(start>end)
		return NULL;
	struct node* temp = newNode(post[*postIndex]);
	(*postIndex)--;
	if(start==end)
		return temp;
	int inIndex = search(in,start,end,temp->data);
	temp->right = build_tree(in,post,inIndex+1,end,postIndex);
	temp->left = build_tree(in,post,start,inIndex-1,postIndex);
	return temp;
}
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int in[100];
	int post[100];
	int n;
	printf("Enter number of nodes in tree: ");
	scanf("%d",&n);
	int i;
	printf("Enter inorder traversal: ");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	printf("Enter postorder traversal: ");
	for(i=0;i<n;i++)
		scanf("%d",&post[i]);
    int postIndex=n-1;
    struct node* root = build_tree(in,post,0,n-1,&postIndex);
    preorder(root);
}