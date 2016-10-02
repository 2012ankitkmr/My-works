#include<bits/stdc++.h>
using namespace std;
bool visited[105][105];
char table[105][105];
int parent[104][105],totcnt;
const int fx[4][2] = {{-1,0}, {0,-1},{0,1}, {1,0} };
void bfs(int i,int j,int r,int c,int number)
{
	pair<int,int>pa;
	queue<pair<int,int> >q;
	pa.first=i;
	pa.second=j;
	parent[i][j]=number;
	q.push(pa);
	int posx,posy;
	visited[i][j]=1;
	while(!q.empty())
	{
	pa=q.front();
	q.pop();
	for(int i=0;i<4;i++)
	{
		posx=pa.first+fx[i][0];
		posy=pa.second+fx[i][1];
		if(posx>=r||posy>=c||posx<0||posy<0||table[posx][posy]=='0')
		continue;
		else
		{
			if(!visited[posx][posy])
			{
				q.push(make_pair(posx,posy));
				visited[posx][posy]=1;
				parent[posx][posy]=number;
			}
		}	
	}		
    }	
}

int checksum(int r,int c)
{
	set<int>myset;
	for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				if(parent[i][j])
				myset.insert(parent[i][j]);
			}
		}
	int net=myset.size();
	return net;
	
}

pair<int,int> findminval(int i,int j,int r,int c)
{

	pair<int,int>pa,minval;
	queue<pair<int,int> >q;
	pa.first=i;
	pa.second=j;
	q.push(pa);
	int posx,posy;
	memset(visited,0,sizeof visited);
	visited[i][j]=1;
minval.first=i,minval.second=j;
	while(!q.empty())
	{
	pa=q.front();
	q.pop();
	for(int i=0;i<4;i++)
	{
		posx=pa.first+fx[i][0];
		posy=pa.second+fx[i][1];
		if(posx>=r||posy>=c||posx<0||posy<0||table[posx][posy]=='0')
		continue;
		else
		{
			if(!visited[posx][posy])
			{
				q.push(make_pair(posx,posy));
				visited[posx][posy]=1;
				minval.first=min(minval.first,posx);
				minval.second=min(minval.second,posy);
			}
			
		}
		
    }
    	
}

return minval;
	
}


void update1(int i,int j,int r,int c)
{
pair<int,int>minval;
minval=findminval(i,j,r,c);	
	
int grandparent=parent[minval.first][minval.second];
memset(visited,0,sizeof visited);
bfs(i,j,r,c,grandparent);

}


void update0(int i,int j,int r,int c)
{
	
	parent[i][j]=0;
	pair<int,int>min_up,min_down,min_left,min_right,refen;
	min_up.first=-1;
	min_up.second=-1;
	min_down.first=-1;
	min_down.second=-1;
	min_left.first=-1;
	min_left.second=-1;
	min_right.first=-1;
	min_right.second=-1;
	

	if(i-1>=0&&table[i-1][j]=='1');
	min_up=findminval(i-1,j,r,c);
	if(i+1<r&&table[i+1][j]=='1');
	min_down=findminval(i+1,j,r,c);
	if(j-1>=0&&table[i][j-1]=='1');
	min_left=findminval(i,j-1,r,c);
	if(j+1<c&&table[i][j+1]=='1');
	min_right=findminval(i,j+1,r,c);
	
	
	
}


int main()
{
	freopen("in.txt","r",stdin);
	int t,r,c,x,y,z,n,ans;
	char s[3];
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
		scanf(" %s",table[i]);
		scanf("%d",&n);
		printf("Case #1: \n");
		totcnt=0;
		memset(visited,0,sizeof visited);
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				if(!visited[i][j]&&table[i][j]=='1')
				{
					totcnt++;
					bfs(i,j,r,c,totcnt);
				}
			}
			
		}
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
			printf("%d ",parent[i][j]);
			}
			printf("\n");
		}
		
		
		for(int i=0;i<n;i++)
		{
			scanf(" %s",s);
			if(s[0]=='Q')
			{
				ans=checksum(r,c);
				printf("%d\n",ans);
			}
			else
			{
				scanf("%d%d%d",&x,&y,&z);
				
				if(z!=(int)(table[x][y]-'0'));
				{
					if(z==1)
					{
						table[x][y]='1';
						update1(x,y,r,c);						
					}
					else if(z==0)
					{
						table[x][y]='0';
						update0(x,y,r,c);					
					}
				}
				
			}
			
		}
		
	}
	return 0;
}
