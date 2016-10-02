#include<bits/stdc++.h>
using namespace std;
bool matrix[50][50];
bool tmatrix[50][50];
int v, e;
bool visited[50];
void readedges()
{
	int i,x,y;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		matrix[x][y]=1;	
	}
	
}
stack<int>mystack;
void dfs(int a)
{

	visited[a]=1;
	for(int i=1;i<=v;i++)
	if(!visited[i]&&matrix[a][i])
	dfs(i);
		mystack.push(a);
}

void transpose()
{
	memset(tmatrix,0,sizeof tmatrix);
	for(int i=1;i<=v;i++)for(int j=1;j<=v;j++)tmatrix[i][j]=matrix[j][i];	
}
void dfsutil(int a)
{
	visited[a]=1;
	printf("%d ",a);	
for(int i=1;i<=v;i++)
{if(!visited[i]&&tmatrix[a][i])
dfsutil(i);	
}
}


void find_SCC()
{
	memset(visited,0,sizeof visited);
for(int i=1;i<=v;i++)
	if(!visited[i])
	dfs(i);
	transpose();
	memset(visited,0,sizeof visited);
	while(!mystack.empty())
	{
		int p=mystack.top();
		
		mystack.pop();
		//printf("stack=%d",p);
		if(!visited[p])
		{
		dfsutil(p);
        printf("\n");
     	}
	}
}


int main()
{
	scanf("%ld%ld",&v,&e);
memset(matrix,0,sizeof matrix);
	readedges();
	find_SCC();
	return 0;
}
