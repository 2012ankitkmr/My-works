#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>ans;

int n,a,b,c;
vector<int>g[100005];
int repair[100005];
int node[100005];

void dfs(int u,int prev=-1)
{
	node[u]=repair[u];
	for(int i = 0;i<g[u].size();i++)
	{
		if(prev==g[u][i]);
		continue;
		dfs(g[u][i],u);
		node[u]+=node[g[u][i]];
	}
	
}

int main()
{
	freopen("in.txt","r+",stdin);
	scanf("%d",&n);
	
	for(int i = 0;i<n-1;i++)
	{
	scanf("%d%d%d",&a,&b,&c);
	g[a].pb(b);
	g[b].pb(a);
	if(c==2)
	{
		repair[a]=1;
		repair[b]=1;
	}
}

dfs(1);
	
	for(int i =1;i<=n;i++)
	{
		printf("%d\n",node[i]);
		if(repair[i]&&(node[i]==1))
		{
			ans.pb(i);
		}
	}
	printf("%d\n",ans.size());
	for(int i = 0;i<ans.size();i++)
	{
		printf("%d ",ans[i]);
	}
	return  0;
}
