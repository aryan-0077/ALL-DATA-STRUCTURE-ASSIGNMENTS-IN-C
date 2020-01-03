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
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* root,int data)
{
	if(root==NULL)
		return newNode(data);
	if(root->data<data)
		root->left = insert(root->left,data);
	else if(root->data>data)
		root->right = insert(root->right,data);
	return root;
}
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node* root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	printf("%d ",root->data);
	preorder(root->right);
}
void postorder(struct node* root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	preorder(root->right);
	printf("%d ",root->data);
}
struct node* inorderSucessor(struct node* root)
{
	struct node* curr = root;
	while(curr!=NULL && curr->left!=NULL)
		curr = curr->left;
	return curr;
}
struct node* delete(struct node* root,int data)
{
	if(root==NULL)
		return root;
	if(root->data<data)
		root->left = delete(root->left,data);
	else if(root->data>data)
		root->right = delete(root->right,data);
	else
	{
		if(root->left==NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node* temp = inorderSucessor(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
		}
	}
	return root;
}
int main()
{
	struct node* root = NULL;
	while(1)
	{
		printf("Press 1 for insertion\nPress 2 for preorder\nPress 3 for inorder\nPress 4 for postorder\nPress 5 for deletion\nPress 6 for exit\n");
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter number you want to insert: ");
			int num;
			scanf("%d",&num);
			root = insert(root,num);
		}
		else if(t==2)
		{
			preorder(root);
			printf("\n");
		}
		else if(t==3)
		{
			inorder(root);
			printf("\n");
		}
		else if(t==4)
		{
			postorder(root);
			printf("\n");
		}
		else if(t==5)
		{
			printf("Enter number you want to delete: ");
			int num;
			scanf("%d",&num);
			root = delete(root,num);
		}
		else
			break;
	}
}