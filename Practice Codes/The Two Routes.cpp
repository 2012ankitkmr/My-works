#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int n,m;

int g1[402][402],g2[402][402],u,v;

int bfs1(int a)
{
	queue<int>q;
	q.push(a);
	
	int cost[402];
	bool vis[402];
	memset(vis,0,sizeof vis);
	for(int i = 1 ; i<=n ; i++)
	cost[i]=inf;
	
	vis[a]=1;
	cost[a]=0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i = 1;i<=n;i++)
		{
			if(g1[p][i])
			{
			
			if(!vis[i])
			{
				vis[i]=1;
				q.push(i);
			}
			cost[i] = min(cost[i],cost[p]+1);
			}
		}	
	}
	return cost[n];
}

int bfs2(int a)
{
	queue<int>q;
	q.push(a);
	
	int cost[402];
	bool vis[402];
	memset(vis,0,sizeof vis);
	for(int i = 1 ; i<=n ; i++)
	cost[i]=inf;
	
	vis[a]=1;
	cost[a]=0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i = 1;i<=n;i++)
		{
			if(g2[p][i])
			{
			
			if(!vis[i])
			{
				vis[i]=1;
				q.push(i);
			}
		
			cost[i] = min(cost[i],cost[p]+1);
	    
			}
		}	
	}
	return cost[n];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		g1[u][v]=1;
		g1[v][u]=1;		
	}
	for(int i = 1;i<=n;i++)
	for(int j  =1;j<=n;j++)
	{
		if(i!=j)
		g2[i][j] = 1-g1[i][j];
	}
	
	int ans1 = bfs1(1);
	int ans2 = bfs2(1);
	if(ans1==inf||ans2==inf)
	printf("-1\n");
	else
	cout<<max(ans1,ans2);
	
	return 0;
}
