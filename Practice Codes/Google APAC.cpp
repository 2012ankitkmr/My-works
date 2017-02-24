#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int a[100005];
bool vis[100005];
vector<int>g[100005];
void dfs(int u)
{
	vis[u]=1;
	
	for(int i = 0;i<g[u].size();i++)
	{
		if(!vis[g[u][i]])
		dfs(g[u][i]);
	}
}


int main()
{
	
	int  n,bit;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	if(i!=a[i])
	{
	g[a[i]].pb(i);
	g[i].pb(a[i]);
     }
	}
	bit=1;
	for(int i = 1;i<=n;i++)
	{
		if(a[i]==1)
		{
		bit=0;	
		}
	}
	int cnt=0;
	for(int i= 1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			cnt++;
		}

		
	}
//	printf("%d\n",cnt);
	int ans = cnt-1+bit;
	printf("%d\n",ans);
	return 0;
}
