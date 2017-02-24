#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first

bool vis[20][20];
char s[2][23];
	int n,m;

void bfs(int a,int b)
{
	queue<pair<int,int> >q;
	q.push(make_pair(a,b));
	vis[a][b]=1;
	int posx,posy;
	while(!q.empty())
	{
		pair<int,int>p =q.front();
		q.pop();
		if(s[0][p.fi]=='>')
		{
			if((p.se<m-1)&&(!vis[p.fi][p.se+1]))
			{
				vis[p.fi][p.se+1]=1;
				q.push(make_pair(p.fi,p.se+1));
			}
		}
		if(s[0][p.fi]=='<')
		{
			if((p.se>0)&&(!vis[p.fi][p.se-1]))
			{
				vis[p.fi][p.se-1]=1;
				q.push(make_pair(p.fi,p.se-1));
			}			
		}
		if(s[1][p.se]=='v')
		{
		    if((p.fi<n-1)&&(!vis[p.fi+1][p.se]))
			{
				vis[p.fi+1][p.se]=1;
				q.push(make_pair(p.fi+1,p.se));
			}
			
		}
		if(s[1][p.se]=='^')
		{
			if((p.fi>0)&&(!vis[p.fi-1][p.se]))
			{
				vis[p.fi-1][p.se]=1;
				q.push(make_pair(p.fi-1,p.se));
			}			
			
		}
		
	}
	
}


int main()
{
//	freopen("in.txt","r+",stdin);
	scanf("%d%d",&n,&m);
	scanf(" %s %s",s[0],s[1]);
	
	int fl=0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			memset(vis,0,sizeof vis);
			bfs(i,j);
			for(int u = 0;u<n;u++)
			for(int v = 0;v<m;v++)
			{
				if(!vis[u][v])
				{   fl=1;
					break;
				}
			}
		}
	}	
	if(fl)
	printf("NO\n");
	else
	printf("YES\n");

	
	return 0;
}
