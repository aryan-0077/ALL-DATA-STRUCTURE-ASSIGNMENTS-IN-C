#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
int equalTree(struct node* root1,struct node* root2)
{
	if(root1 == NULL && root2== NULL)
		return 1;
	if(root1 == NULL)
		return 0;
	if(root2 == NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;
	int check1 = equalTree(root1->left,root2->left);
	int check2 = equalTree(root1->right,root2->right);
	return (check1&check2);
}
int main()
{
	struct node* root = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	struct node* second = (struct node*)malloc(sizeof(struct node));
	struct node* third = (struct node*)malloc(sizeof(struct node));
	struct node* four = (struct node*)malloc(sizeof(struct node));
	struct node* five = (struct node*)malloc(sizeof(struct node));
	struct node* six = (struct node*)malloc(sizeof(struct node));
	root->data=1;
	first->data=2;
	second->data=3;
	third->data=4;
	four->data=5;
	five->data=6;
	six->data=7;
	root->left=first;
	root->right=second;
	first->left=third;
	first->right=four;
	second->left=five;
	second->right=six;
	third->left=NULL;
	third->right=NULL;
	four->left=NULL;
	four->right=NULL;
	five->left=NULL;
	five->right=NULL;
	six->left=NULL;
	six->right=NULL;
    if(equalTree(root,root))
    	printf("Trees are equal\n");
    else
    	printf("Trees are not equal\n");
}