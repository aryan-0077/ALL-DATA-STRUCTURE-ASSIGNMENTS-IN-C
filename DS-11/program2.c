#include<stdio.h>
struct node
{
	int ar[100];
	int front;
	int rear;
};
int isEmpty(struct node* queue)
{
	if(queue->front>queue->rear)
		return 1;
	return 0;
}
void enqueue(struct node* queue,int data)
{
	queue->rear++;
	queue->ar[queue->rear] = data;
}
int dequeue(struct node* queue)
{
	if(isEmpty(queue))
		return -1;
	int data = queue->ar[queue->front];
	queue->front++;
	return data;
}
int adj[100][100];
int n;
void bfs(int vertex)
{
	int visited[100];
	for(int i=0;i<n;i++)
		visited[i] = 0;
	struct node queue;
	queue.front = 0;
	queue.rear = -1;
	enqueue(&queue,vertex);
	while(!isEmpty(&queue))
	{
		int data = dequeue(&queue);
		if(visited[data]==1)
			continue;
		printf("%d ",data);
		visited[data] = 1;
		for(int i=0;i<n;i++)
		{
			if(adj[data][i])
			{
				if(!visited[i])
					enqueue(&queue,i);
			}
		}
	}
}
int main()
{
	int m;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("Enter number of edges: ");
	scanf("%d",&m);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			adj[i][j] = 0;
	}
	for(i=0;i<m;i++)
	{
		int u,v;
		printf("Enter edge: ");
		scanf("%d%d",&u,&v);
		adj[u][v] = adj[v][u] = 1;
	}
	bfs(0);
}