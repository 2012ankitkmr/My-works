#include<bits/stdc++.h>
using namespace std;

bool visited[5000];
struct graph 
{
	int numv;
	int nume;
	int **adjmatrix;
};
struct graph *G=(struct graph*)malloc(sizeof(struct graph));

void readedge(int size,int choice)
{
int i,u,v;
if(choice==2)
{
	for(i=0;i<size;i++)
	{ //printf("Enter the edges : ");
		scanf("%d%d",&u,&v);
G->adjmatrix[u][v]=1;
G->adjmatrix[v][u]=1;

	}
}
else
{
	for(i=0;i<size;i++)
	{ //printf("Enter the edges : ");
		scanf("%d%d",&u,&v);
G->adjmatrix[u][v]=1;
	}
}

}

void DFS(int a)
{ int i;
	visited[a]=1;
	printf("node %d\n",a);
	for(i=1;i<=G->numv;i++)
	{
		if(!visited[i]&&G->adjmatrix[a][i])
		DFS(i);
	}
}
	

void BFS(int a)
{
int rear=1,que[5000],front=1;
	int i,root;
visited[a]=1;
que[rear++]=a;	
//printf("front =%d,rear=%d ",front,rear);
//	printf("%d\n",a);
while(front!=rear)
{
for(i=1;i<=G->numv;i++)
printf("%d ",visited[i]);
printf("\n");

	root=que[front];
for(i=1;i<=G->numv;i++)
{

	if(!visited[i]&&G->adjmatrix[root][i])
	{visited[i]=1;
	que[rear++]=i;
//printf("%dhere,root=%d\n",i,root);
}
}
front++;
}	
}	
int main()
{
	int i,j,choice;
	//printf("Enter the vertices to enter : ");
	scanf("%d",&G->numv);
	//printf("Enter the edges to enter: ");
	scanf("%d",&G->nume);

	G->adjmatrix=(int**)malloc(G->numv*sizeof(int*));
	for(i=0;i<=G->numv;i++)
	G->adjmatrix[i]=(int*)malloc(G->numv*sizeof(int));

	//if(!G->adjmatrix)
	//printf("cannot allocate memory\n");

	for(i=1;i<=G->numv;i++)
	{
		for(j=1;j<=G->numv;j++)
		G->adjmatrix[i][j]=0;
	}
	
	//printf("Enter the graph type\n1.Directed\n2.Undirected\n");
	scanf("%d",&choice);
	readedge(G->nume,choice);
	
	for(i=1;i<=G->numv;i++)
	{
	for(j=1;j<=G->numv;j++)
	{
	printf("%d ",G->adjmatrix[i][j]);
	}
	printf("\n");	
	}
	//visited is a 1D array
	for(i=1;i<=G->numv;i++)
	{
		visited[i]=0;
	}
	int ch;
scanf("%d",&ch);
if(ch==1)
{

printf("Going For Dfs\n");
	for(i=1;i<=G->numv;i++)
		DFS(i);
}
else
{
	printf("Going For BFS\n");
 //for(i=1;i<=G->numv;i++)
   BFS(1);
}	
return 0;	
}

