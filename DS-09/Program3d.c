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
int height(struct node* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));		
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
	printf("Height of binary tree: %d",height(root));
	return 0;
}