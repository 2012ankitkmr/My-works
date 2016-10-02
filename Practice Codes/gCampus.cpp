#include<bits/stdc++.h>
using namespace std;

int graph[105][105],cnt[105][105];
int dist[105];
void floyd(int n)
{
bool visited[105];
memset(visited,0,sizeof visited);
visited[0]=1;
queue<int>q;
q.push(0);
memset(dist,5444444,sizeof dist);
dist[0]=0;
while(!q.empty())
{
	int p=q.front();
	q.pop();
	
	for(int i=0;i<n;i++)
	{
		if(graph[p][i])
		{
		dist[i]=min(dist[p]+graph[p][i],dist[i]);	
			
		}
		
	}
	
	
}	
	
	
}


int main()
{
	int n,m,t,a,b,c;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		memset(graph,0,sizeof graph);
		memset(cnt,0,sizeof cnt);

		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			graph[a][b]=c;
			graph[b][a]=c;
			cnt[a][b]=i;
		}
		floyd(n);	
		
	}
	
	
	return 0;
}
