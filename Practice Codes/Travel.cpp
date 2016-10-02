#include<bits/stdc++.h>
using namespace std;

#define INF 144444444
int network[502][502][25];
int dist[505][25];

void floyd(int n)
{
	memset(dist,0,sizeof visited);
	for(int clock=0;clock<24;clock++)
	{
	bool visited[505];
	memset(visited,0,sizeof visited);
for(int i=0;i<=n+1;i++)
dist[i][clock]=INF;
	queue<int>q;
	q.push(1);
	dist[1][clock]=0;
	visited[1]=1;
while(!q.empty())
{
	int p=q.front();
	q.pop();
	for(int i=1;i<=n;i++)
	{
		if(network[p][i][clock])
		{
			dist[i][clock]=min(dist[i][clock],network[p][i][clock]+dist[p][clock]);
			if(!visited[i])
			{
			q.push(i);
visited[i]=1;
		}
		}	
	}	
}	
	
    }
}


int main()
{
//freopen("A-large-practice.in","r",stdin);
//freopen("out.txt","w+",stdout);
	int t,n,m,k,a,b,c,d,s;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
	memset(network,0,sizeof network);
	scanf("%d%d%d",&n,&m,&k);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<24;i++)
		{
			scanf("%d",&c);
			network[a][b][i]=c;
			network[b][a][i]=c;
		}		
	}
	
	floyd(n);	
	
	printf("Case #%d: ",test);
	
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&d,&s);
		if(dist[d][s]==INF)
		printf("-1 ");
		else
		printf("%d ",dist[d][s]);	
	}
	
	printf("\n");	
	}
	
	return 0;
}
