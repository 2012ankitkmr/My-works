#include<bits/stdc++.h>
using namespace std;
#define inf 1e15
#define ll long long
#define mp make_pair
#define pb push_back
#define se second
#define fi first
vector<pair<int,ll> >g[100005];
int n,m,a,b;
	ll cost[100005],c;
	
void bfs()
{
	queue<int >q;
	q.push(1);
	for(int i =0;i<=100003;i++)
	cost[i]=inf;
	bool vis[100005];
	memset(vis,0,sizeof vis);
	cost[1]=0;
	vis[1]=1;
	while(!q.empty())
	{
	    int p = q.front();
		q.pop();
		
		for(int i =0;i<g[p].size();i++)
		{
			pair<int,ll> temp = g[p][i];
			if(!vis[temp.fi])
			{
				vis[temp.fi]=1;
				q.push(temp.fi);
			}
			cost[temp.fi] = min(cost[temp.fi],temp.se+cost[p]);
		}
		
	}
}	

int main()
{
freopen("in.txt","r+",stdin);
	scanf("%d%d",&n,&m);
	
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d%I64d",&a,&b,&c);
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));		
	}
	
	bfs();
	if(cost[n]==inf)
	{
		printf("-1\n");
		return 0;
	}
	int p = n,min_val,ind;
stack<int>ms;
ms.push(n);

for(int i =1;i<=n;i++)
printf("%lld ",cost[i]);
	while(p!=1)
	{
		min_val =INT_MAX,ind;
		for(int i =0;i<g[p].size();i++)
		{
			pair<int,ll >temp = g[p][i];
			
			if(min_val>cost[temp.fi])
			{
				min_val = cost[temp.fi];
				ind = temp.fi;
			}
			
		}
		p = ind;
		ms.push(p);
	}
	
	while(!ms.empty())
	{
		printf("%d ",ms.top());
		ms.pop();
	}
	printf("\n");
	return 0;
}
