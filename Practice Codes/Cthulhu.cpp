#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m,a,b;
vector<int>g[102];
bool vis[102];
void bfs()
{
queue<int>q;
q.push(1);
memset(vis,0,sizeof vis);
vis[1]=1;

while(!q.empty())
{
	int p = q.front();
	q.pop();
	for(int i =0;i<g[p].size();i++)
	{
		if(!vis[g[p][i]])
		{
			vis[g[p][i]]=1;
			q.push(g[p][i]);
		}
		
	}
}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs();
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			fl=1;
			break;
		}
	}
	if(fl||(n!=m))
	{
		printf("NO\n");
	}
	else
	printf("FHTAGN!\n");

	
	
	return  0;
}
