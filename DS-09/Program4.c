#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int val;
	bool lthread, rthread;
	struct node *left, *right;
} NODE;

NODE *insert(NODE *root, int ikey)
{
	NODE *tmp,*par,*ptr;
	int found=0;
	ptr = root;
	par = NULL;
	while( ptr!=NULL )
	{
		if( ikey == ptr->val)
		{
			found =1;
			break;
		}
		par = ptr;
		if(ikey < ptr->val)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}
	if(found)
		printf("Duplicate key");
	else
	{
		tmp=(NODE *)malloc(sizeof(NODE));
		tmp->val=ikey;
		tmp->lthread = true;
		tmp->rthread = true;
		if(par==NULL)
		{
			root=tmp;
			tmp->left=NULL;
			tmp->right=NULL;
		}
		else if( ikey < par->val )
		{
			tmp->left=par->left;
			tmp->right=par;
			par->lthread=false;
			par->left=tmp;
		}
		else
		{
			tmp->left=par;
			tmp->right=par->right;
			par->rthread=false;
			par->right=tmp;
		}
	}
	return root;
}

NODE *in_succ(NODE *ptr)
{
	if(ptr->rthread==true)
		return ptr->right;
	else
	{
		ptr=ptr->right;
		while(ptr->lthread==false)
			ptr=ptr->left;
		return ptr;
	}
}

NODE *in_pred(NODE *ptr)
{
	if(ptr->lthread==true)
		return ptr->left;
	else
	{
		ptr=ptr->left;
		while(ptr->rthread==false)
			ptr=ptr->right;
		return ptr;
	}
}

NODE *case_a(NODE *root, NODE *par,NODE *ptr )
{
	if(par==NULL) /*root node to be deleted*/
		root=NULL;
	else if(ptr==par->left)
	{
		par->lthread=true;
		par->left=ptr->left;
	}
	else
	{
		par->rthread=true;
		par->right=ptr->right;
	}
	free(ptr);
	return root;
}

NODE *case_b(NODE *root,NODE *par,NODE *ptr)
{
	NODE *child,*s,*p;
	if(ptr->lthread==false) /*node to be deleted has left child */
		child=ptr->left;
	else                /*node to be deleted has right child */
		child=ptr->right;
	if(par==NULL )   /*node to be deleted is root node*/
		root=child;
	else if( ptr==par->left) /*node is left child of its parent*/
		par->left=child;
	else                     /*node is right child of its parent*/
		par->right=child;
	s=in_succ(ptr);
	p=in_pred(ptr);
	if(ptr->lthread==false) /*if ptr has left subtree */
			p->right=s;
	else
	{
		if(ptr->rthread==false) /*if ptr has right subtree*/
			s->left=p;
	}
	free(ptr);
	return root;
}

NODE *case_c(NODE *root, NODE *par,NODE *ptr)
{
	NODE *succ,*parsucc;
	/*Find inorder successor and its parent*/
	parsucc = ptr;
	succ = ptr->right;
	while(succ->left!=NULL)
	{
		parsucc = succ;
		succ = succ->left;
	}
	ptr->val = succ->val;
	if(succ->lthread==true && succ->rthread==true)
		root = case_a(root, parsucc,succ);
	else
		root = case_b(root, parsucc,succ);
	return root;
}

NODE *del(NODE *root, int dkey)
{
	NODE *par,*ptr;
	int found=0;
	ptr = root;
	par = NULL;
	while( ptr!=NULL)
	{
		if( dkey == ptr->val)
		{
			found =1;
			break;
		}
		par = ptr;
		if(dkey < ptr->val)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}
	if(found==0)
		printf("dkey not present in tree");
	else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
		root = case_c(root,par,ptr);
	else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
	else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
	else /*no child*/
		root = case_a(root,par,ptr);
	return root;
}

void inorder(NODE *root)
{
	NODE *ptr;
	if(root == NULL )
	{
		printf("Tree is empty");
		return;
	}
	ptr=root;
	/*Find the leftmost node */
	while(ptr->lthread==false)
		ptr=ptr->left;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=in_succ(ptr);
	}
}

void preorder(NODE *root)
{
	NODE *ptr;
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		if(ptr->lthread==false)
			ptr=ptr->left;
		else if(ptr->rthread==false)
			ptr=ptr->right;
		else
		{
			while(ptr!=NULL && ptr->rthread==true)
				ptr=ptr->right;
			if(ptr!=NULL)
				ptr=ptr->right;
		}
	}
}

void postorder(NODE *root)
{
	if(root==NULL)
		return;
	if(root->lthread==false)
		postorder(root->left);
	if(root->rthread==false)
		postorder(root->right);
	printf("%d, ",root->val);
}

int main()
{
	int op,num;
	NODE *root=NULL;
	while(1)
	{
		printf("\n1. Insert, 2. Delete, 3. Inorder Traversal, 4. Preorder Traversal, 5. Postorder Traversal, 6. Quit. Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			root = insert(root,num);
			break;
		case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			root = del(root,num);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			preorder(root);
			break;
		case 5:
			postorder(root);
			break;
		case 6:
			return 0;
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}