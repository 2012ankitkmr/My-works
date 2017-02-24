#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>g[100005];

int n,m,a,b;
int col[100005];
	bool vis[100005];

bool color(int x)
{
	queue<int>q;
	q.push(x);
	col[x]=0;
	vis[x]=1;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i = 0;i<g[p].size();i++)
		{
			if(!vis[g[p][i]])
			{
				vis[g[p][i]]=1;
				q.push(g[p][i]);
			}
			if(col[g[p][i]]==col[p])
			return false;
			col[g[p][i]]=1-col[p];
		}
		
	}
	return true;
}

int colcount(int c)
{
	int cnt=0;
	for(int i = 1;i<=n;i++)
	if((col[i]==c)&&(g[i].size()!=0))
	cnt++;
	return cnt;
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
		memset(col,-1,sizeof col);
	memset(vis,0,sizeof vis);

	for(int i  =1;i<=n;i++)
	{
	if(!vis[i])
	{
	
	bool ans = color(i);
	if(!ans)
	{
	printf("-1\n");
	return 0;  
    }  
}
}
		int num1 = colcount(1);
		printf("%d\n",num1);
		for(int i = 1;i<=n;i++)
		if(col[i]==1&&(g[i].size()!=0))
		printf("%d ",i);
		printf("\n");
		
		int num2 = colcount(0);
		printf("%d\n",num2);
		for(int i = 1;i<=n;i++)
		if(col[i]==0&&(g[i].size()!=0))
		printf("%d ",i);
		printf("\n");	
	
	return 0;
	
}
