#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	printf("%d ",root->data);
	preorder(root->right);
}
struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int search(int in[],int start,int end,int val)
{
	for(int i=start;i<=end;i++)
	{
		if(in[i]==val)
			return i;
	}
	return -1;
}
struct node* build_tree(int in[],int pre[],int start,int end)
{
	if(start>end)
		return NULL;
	static int preIndex = 0;
	struct node* temp = newNode(pre[preIndex++]);
	if(start==end)
		return temp;
	int inIndex = search(in,start,end,temp->data);
	temp->left = build_tree(in,pre,start,inIndex-1);
	temp->right = build_tree(in,pre,inIndex+1,end);
	return temp;
}
int main()
{
	int in[100];
	int pre[100];
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter inorder traversal: ");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	printf("Enter preorder traversal: ");
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	struct node* root = build_tree(in,pre,0,n-1);
	preorder(root);
}