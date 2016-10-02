#include<bits/stdc++.h>
using namespace std;
bool matrix[1000][1000];
bool visited[1000];

void readedges(int size)
{
	int i,x,y;
	
	for(i=0;i<size;i++)
	{
		scanf("%d%d",&x,&y);
		matrix[x][y]=1;
	}
	
}
int flag=0;
bool cyclic(int a,int v)
{
	visited[a]=1;
	int i;
	for(i=1;i<=v;i++)
	{
		if(matrix[a][i]==1)
		{
			if(visited[i])
			{
				flag=1;
		break;
			}
			else
			cyclic(i,v);
			
		}
		
	}
	return flag;
	
}

int main()
{
	int v,e;
	scanf("%d",&v);
	scanf("%d",&e);
	
	memset(matrix,0,sizeof matrix);
	
	readedges(e);
	
	memset(visited,0,sizeof visited);
	
	if(cyclic(1,v))
	printf("CYCLIC\n");
	else
	printf("NON CYCLIC\n");
	return 0;
}
