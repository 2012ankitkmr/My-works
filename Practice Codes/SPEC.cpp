#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define se second
#define fi first 
int n,m,x,y,d;


int fx[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};
int mat[102][102],dis[102][102],visited[102][102];

int bfs()
{
	queue<pair<int,int> >q;
	q.push(make_pair(1,1));
	
	for(int i =1;i<=m;i++)
	for(int j = 1;j<=n;j++)
	{
	dis[i][j]=inf;
	visited[i][j]=0;
   }
	int posx,posy;
pair<int,int>p;

dis[1][1]=0;
visited[1][1]=1;
	while(!q.empty())
	{
		p =q.front();
		q.pop();
		for(int i = 0;i<4;i++)
		{
			posx = p.fi+fx[i][0];
			posy = p.se+fx[i][1];
			if(posx<1||posy<1||posy>n||posx>m||abs(mat[posx][posy]-mat[p.fi][p.se])>d)
			continue;
			else
			{
				if(!visited[posx][posy])
				{
					visited[posx][posy]=1;
					q.push(make_pair(posx,posy));
				}
				dis[posx][posy] = min(dis[posx][posy],dis[p.fi][p.se]+1);
			}
			
		}
		
	}

	if(dis[x][y]==inf)
	return -1;
	else
	return dis[x][y]-1;
	
}

int main()
{
//	freopen("in.txt","r+",stdin);
int t;
cin>>t;
while(t--)
{
scanf("%d%d%d%d%d",&m,&n,&x,&y,&d);
for(int i = 1 ; i<=m;i++)
{
	for(int j=1;j<=n;j++)
	scanf("%d",&mat[i][j]);
}	
printf("%d\n",bfs());	
	
}	
	return 0;
}
