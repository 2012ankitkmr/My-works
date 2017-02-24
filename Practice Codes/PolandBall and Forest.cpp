#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int a[10004];


int color[10004];
vector<int>g[10004];
bool vis[10004];

void dfs(int a,int col)
{
	vis[a]=1;
	color[a]=col;
	for(int i = 0;i<g[a].size();i++)
	{
		if(!vis[g[a][i]])
		dfs(g[a][i],col);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	g[a[i]].pb(i);
	g[i].pb(a[i]);
}
int col=0;
for(int i =1;i<=n;i++)
{
	if(!vis[i])
	{
		++col;
		dfs(i,col);
	}
}

printf("%d\n",col);

return 0;
}
