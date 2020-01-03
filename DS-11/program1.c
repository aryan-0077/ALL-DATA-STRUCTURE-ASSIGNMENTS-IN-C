#include<stdio.h>
int adj[100][100];
int n;
void dfsUtil(int vertex,int visited[])
{
	if(visited[vertex])
		return;
	visited[vertex] = 1;
	printf("%d ",vertex);
	for(int i=0;i<n;i++)
	{
		if(adj[vertex][i])
			dfsUtil(i,visited);
	}
}
void dfs(int vertex)
{
	int visited[100];
	for(int i=0;i<n;i++)
		visited[i] = 0;
	dfsUtil(vertex,visited);
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
	dfs(0);
}