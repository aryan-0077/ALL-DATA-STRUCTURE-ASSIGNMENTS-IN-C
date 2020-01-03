#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int adj[100][100];
int n;
void printMst(int parent[])
{
	for(int i=1;i<n;i++)
		printf("%d --> %d\n",parent[i],i);
}
int minKey(int key[],bool mstSet[])
{
	int min = INT_MAX,min_index;
	for (int v = 0; v < n; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v; 
    return min_index; 
}
void primMst()
{
	int parent[n];
	int key[n];
	bool mtSet[n];
	for(int i=0;i<n;i++)
	{
		key[i] = INT_MAX;
		mtSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for(int i=0;i<n-1;i++)
	{
		int u = minKey(key,mtSet);
		mtSet[u] = true;
		for(int j=0;j<n;j++)
		{
			if(adj[u][j] && !mtSet[j] && adj[u][j]<key[j])
			{
				parent[j] = u;
				key[j] = adj[u][j];
			}
		}
	}
	printMst(parent);
}
int main()
{
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			adj[i][j] = 0;
	}
	printf("Enter number of edges: ");
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u][v] = w;
		adj[v][u] = w;
	}
	primMst();
	return 0;
}