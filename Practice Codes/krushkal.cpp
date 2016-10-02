#include<bits/stdc++.h>
#define INF 9999
using namespace std;
int parent[5000];
struct graph
{
	int v;
	int e;
	int **adj;
	int **weight;
};

struct graph *G=(struct graph*)malloc(sizeof(struct graph));

void readedges(int size)
{
	int i,x,y,z;
	for(i=1;i<=size;i++)
	{
	scanf("%d%d%d",&x,&y,&z);
	G->adj[x][y]=1;
	G->adj[y][x]=1;
	G->weight[x][y]=z;
	}
	
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int funion(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void krushkal()
{

	int i,j,t=1,min,mincost=0,a,b,u,v;
	while(t<G->v)
	{
		//printf("here\n");
	for(i=1,min=INF;i<=G->v;i++)
	{
		for(j=1;j<=G->v;j++)
		{
			if(G->weight[i][j]<min)
			{
				min=G->weight[i][j];
				a=u=i;
				b=v=j;
			}
		}
	}	
	u=find(u);
	v=find(v);
	if(funion(u,v))
	{
		t++;
		mincost+=min;
			}	
		G->weight[a][b]=G->weight[b][a]=INF;
	}
	printf("minimum cost=%d\n",mincost);
}

int main()
{
	int i,j;
	scanf("%d",&G->v);
	scanf("%d",&G->e);
	
	G->adj=(int**)malloc(G->v*sizeof(struct graph*));
	for(i=0;i<=G->v;i++)
	G->adj[i]=(int*)malloc(G->v*sizeof(struct graph));
	
	G->weight=(int**)malloc(G->v*sizeof(struct graph*));
	for(i=0;i<=G->v;i++)
	G->weight[i]=(int*)malloc(G->v*sizeof(struct graph));
	
	
	
	for(i=1;i<=G->v;i++)
	{
		for(j=1;j<=G->v;j++)
		{
			G->adj[i][j]=0;
			G->weight[i][j]=INF;
		}
	}
	readedges(G->e);
	memset(parent,0,sizeof parent);
	
	for(i=1;i<=G->v;i++)
	{
		for(j=1;j<=G->v;j++)
		{
			printf("%d ",G->adj[i][j]);
			
		}
		printf("\n");
	}
	krushkal();
	return 0;
}
