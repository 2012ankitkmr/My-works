#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool matrix[1000][1000];
int colour[1000],v;
void readedges(int size)
{
	int i,x,y;
	for(i=1;i<=size;i++)
	{
		scanf("%d%d",&x,&y);
		matrix[x][y]=1;
		matrix[y][x]=1;
	}
	
}

bool isbipartite(int src)
{
	memset(colour,-1,sizeof colour);
	colour[src]=1;
	int p,i;
	queue<int>q;
	q.push(src);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(i=1;i<=v;i++)
		{
			if(matrix[p][i]==1&&colour[i]==-1)
			{
				colour[i]=1-colour[p];
				q.push(i);
			}
                else if(matrix[p][i]&&colour[i]==colour[p])
                return 0;
		}
		
	}
	return 1;
}

int main()
{
 int e;
	
	scanf("%d",&v);
	scanf("%d",&e);
	memset(matrix,0,sizeof matrix);
	readedges(e);
	if(isbipartite(1))
	
	return 0;
}
