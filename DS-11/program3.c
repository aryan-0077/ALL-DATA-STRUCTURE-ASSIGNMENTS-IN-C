#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* next;
	int vertex;
};
struct node* adj[100];
int visited[100];
int n,m;
struct node* newNode(int vertex)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->vertex = vertex;
	return temp;
}
struct node* insert(struct node* head,struct node* temp)
{
	temp->next = head;
	return temp;
}
struct node* delete(struct node* head,int temp)
{
	if(head==NULL)
		return head;
	if(head->vertex==temp)
	{
		struct node* temp1 = head;
		head = head->next;
		free(temp1);
		return head;
	}
	if(head->next==NULL)
	{
		return head;
	}
	struct node* p = head;
	while(p->next!=NULL)
	{
		if(p->next->vertex==temp)
		{
			struct node* temp1 = p->next;
			p->next = temp1->next;
			free(temp1);
			return head;
		}
		p = p->next;
	}
	return head;
}
void add_edge(int i,int j)
{
	struct node* temp = newNode(j);
	adj[i] = insert(adj[i],temp);
	struct node* temp1 = newNode(i);
	adj[j] = insert(adj[j],temp1);
}
void remove_edge(int i,int j)
{
	adj[i] = delete(adj[i],j);
	adj[j] = delete(adj[j],i);
}
void dfs(int vertex)
{
	printf("%d ",vertex);
	visited[vertex] = 1;
	struct node* p = adj[vertex];
	while(p!=NULL)
	{
		vertex = p->vertex;
		if(!visited[vertex])
			dfs(vertex);
		p = p->next;
	}
}
int length(struct node* head)
{
	if(head==NULL)
		return 0;
	return 1+length(head->next);
}
void remove_node(int vertex)
{
	while(adj[vertex]!=NULL)
	{
		remove_edge(vertex,adj[vertex]->vertex);
	}
}
int main()
{
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter number of edges: ");
	scanf("%d",&m);
	int i;
	for(i=0;i<n;i++)
		adj[i] = NULL;
	printf("Enter edges: ");
	for(i=0;i<m;i++)
	{
		int temp1,temp2;
		scanf("%d%d",&temp1,&temp2);
		add_edge(temp1,temp2);
	}
	while(1)
	{
		printf("Press 1 to add Edge\nPress 2 to remove edge\nPress 3 to find degree\nPress 4 to add node\nPress 5 to delete node\nPress 6 to display\nPress 7 to exit\n");
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			printf("Entre ends of edge: ");
			int temp1,temp2;
			scanf("%d%d",&temp1,&temp2);
			add_edge(temp1,temp2);
		}
		else if(t==2)
		{
			printf("Entre ends of edge: ");
			int temp1,temp2;
			scanf("%d%d",&temp1,&temp2);
			remove_edge(temp1,temp2);
		}
		else if(t==3)
		{
			printf("Enter vertex: ");
			int vertex;
			scanf("%d",&vertex);
			int degree = length(adj[vertex]);
			printf("%d\n",degree);
		}
		else if(t==4)
		{
			printf("Enter vertex: ");
			int vertex;
			scanf("%d",&vertex);
			adj[vertex] = NULL;
		}
		else if(t==5)
		{
			printf("Enter vertex: ");
			int vertex;
			scanf("%d",vertex);
			remove_node(vertex);
		}
		else if(t==6)
		{
			for(int i=0;i<100;i++)
				visited[i]=0;
			printf("Enter vertex: ");
			int vertex;
			scanf("%d",&vertex);
			dfs(vertex);
			printf("\n");
		}
		else
			break;
	}
}
