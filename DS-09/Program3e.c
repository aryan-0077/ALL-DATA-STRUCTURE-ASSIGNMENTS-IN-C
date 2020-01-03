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
	temp->left = NULL;
	temp->right = NULL;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int check(struct node* root)
{
	if(root==NULL)
		return 1;
	if(root->left==NULL && root->right!=NULL)
		return 0;
	if(root->left!=NULL && root->right==NULL)
		return 0;
	return check(root->left)&check(root->right);	
}
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	if(check(root))
		printf("Strict binary tree\n");
	else
		printf("Not a strict binary tree\n");
	return 0;
}