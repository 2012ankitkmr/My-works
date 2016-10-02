#include<bits/stdc++.h>
#include<queue>
#include<vector>
#define INF 100000
using namespace std;
int dis[5000];
int que[5000];
int path[5000];

struct graph
{
	int v;
	int e;
	int **adj;
    int **weight;
};
struct graph *G=(struct graph*)malloc(sizeof(struct graph));

void readedges(int size,int choice)
{
//	printf("reading edges\n");
	int i,x,y,z;
	if(choice==1)
	{
		for(i=1;i<=size;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		G->adj[x][y]=1;
		G->weight[x][y]=z;
}
	}
	else
	{
			for(i=1;i<=size;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		G->adj[x][y]=1;
		G->adj[y][x]=1;
        G->weight[x][y]=z;
    
	    G->weight[y][x]=z;
}
	}

//	printf("exiting reading edges\n");	
}

void Dijkstra(int src,int des)
{
//	printf("in dijsktra\n");
int small,current,start,new1,temp,i;
for(i=1;i<=G->v;i++)
dis[i]=INF;
que[src]=1;
dis[src]=0;
current=src;
	//printf("in dijsktra\n");
while(current!=des)
{
	small=INF;
	start=dis[current];
	printf("start=%d\n",start);
	for(i=1;i<=G->v;i++)
	{
		if(que[i]==0)
		{
			
		new1=start+G->weight[current][i];
		printf("new=%d\n",new1);
		if(new1<dis[i])
		{
			dis[i]=new1;
			path[i]=current;
		}
		printf("%ld %ld\n",dis[i],small);
		if(dis[i]<small)
		{
	    small=dis[i];
		 temp=i;
	       		//printf("temp=%d\n",temp);
		}		

			}
	}
	printf("\n");

	current=temp;

	que[current]=1;
	printf("current=%d\n",current);
}
for(i=1;i<=G->v;i++)
printf("The minimum cost is %d\n",dis[i]);
}

int main()
{
	int i;
	scanf("%d",&G->v);
	
	scanf("%d",&G->e);
	 
 G->adj=(int**)malloc(G->v*sizeof(struct graph*));
	
	for(i=0;i<=G->v;i++)
	G->adj[i]=(int*)malloc(G->v*sizeof(struct graph));
	
	G->weight=(int**)malloc(G->e*sizeof(struct graph*));
	
	for(i=0;i<=G->v;i++)
	G->weight[i]=(int*)malloc(G->e*sizeof(struct graph));
//printf("memory allocated\n");	
int choice,j;
for(i=1;i<=G->v;i++)
{
	for(j=1;j<=G->v;j++)
	{G->adj[i][j]=0;	
G->weight[i][j]=INF;
}
}


scanf("%d",&choice);//1.directed graph 2.undirected graph
readedges(G->e,choice);	

for(i=1;i<=G->v;i++)
{
	for(j=1;j<=G->v;j++)
	printf("%d ",G->weight[i][j]);
	printf("\n");
}	

Dijkstra(2,4);	
	
	return 0;
}

