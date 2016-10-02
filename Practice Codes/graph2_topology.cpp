#include<bits/stdc++.h>
using namespace std;

bool visited[5000];
int indegree[5000];
struct graph
{
	int v;
	int e;

	int **adj;//adjmatrix
};
struct graph *G=(struct graph*)malloc(sizeof(struct graph));
void readvalues(int a)
{
	int i,x,y;
	if(a==1)
	{
	for(i=1;i<=G->e;i++)
	{
		scanf("%d%d",&x,&y);
		G->adj[x][y]=1;
	}			
	}
	else
	{
	for(i=1;i<=G->e;i++)
	{
		scanf("%d%d",&x,&y);
		G->adj[x][y]=1;
		G->adj[y][x]=1;
	}	
	}
	
}
void indegreecheck()
{
	int i,j;
	
	for(i=1;i<=G->v;i++)
	{
		for(j=1;j<=G->v;j++)
		{
		if(G->adj[i][j]==1)
		indegree[j]++;	
		}
	}	
}void topological_order(int n)
{
	int counter=0;
	queue<int>q;
	min_degree=0;
	ge(i,1,n)
	if(indegree[i]==min_degree)
	q.push(i);
vec topological;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
	//	ank::show(p);
	topological.pb(p);	
		for(int i=1;i<=n;i++)
		{
			if(matrix[p][i])
			{
				matrix[p][i]=0;
				--indegree[i];
				if(!indegree[i])
				q.push(i);	
			}	
		}
	}

	printA(topological,0,n-1);
}

int main()
{
	int i,j;
scanf("%d",&G->v);

scanf("%d",&G->e);

G->adj=(int**)malloc(G->v*sizeof(int*));

for(i=0;i<=G->v;i++)
G->adj[i]=(int*)malloc(G->v*sizeof(int));

for(i=1;i<=G->v;i++)
{
	for(j=1;j<=G->v;j++)
	G->adj[i][j]=0;
}

memset(visited,0,sizeof visited);

int choice;
scanf("%d",&choice);//1->directed  2->undirected

readvalues(choice);

for(i=1;i<=G->v;i++)
{
	for(j=1;j<=G->v;j++)
	printf("%d ",G->adj[i][j]);
	printf("\n");
}

topologicalsort(); 

	return 0;
}
