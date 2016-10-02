#include<bits/stdc++.h>
#include<limits.h>
#define MAX 2000000007
using namespace std;
long int adj[1005][1005];
long int parent[1005];

void readedges(long int size)
{
	long int i,x,y,z;
	
	for(i=1;i<=size;i++)
	{
		scanf("%ld%ld%ld",&x,&y,&z);
		adj[x][y]=z;
		adj[y][x]=z;
	}
	
}
long int find(long int i)
{
	while(parent[i])
	{
		i=parent[i];
	}
	return i;
}

bool funion(long int a,long int b)
{
	if(a!=b)
	{
		parent[b]=a;
		return 1;
	}
	return 0;
}
void krushkal(long int size,long int e,long int m)
{
	long int i,j,t=1,mincost=0,min,a,b,u,v;
	while(t<size)
	{
		for(i=1,min=MAX;i<=size;i++)
		{
			for(j=1;j<=size;j++)
			{
				if(adj[i][j]<min)
				{
					min=adj[i][j];
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
		
		adj[a][b]=adj[b][a]=MAX;
	}
	printf("%ld\n",mincost);
}

int main()
{
	int t;
	long int p,v,e;
	for(scanf("%d",&t);t--;)
	{
		scanf("%ld%ld%ld",&p,&v,&e);
		memset(parent,0,sizeof(parent));
	memset(adj,MAX,sizeof(adj));
	readedges(e);
	krushkal(v,e,p);
	
	}
	return 0;
}
