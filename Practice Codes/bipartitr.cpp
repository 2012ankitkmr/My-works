#include<bits/stdc++.h>
using namespace std;
bool matrix[100][100];
int v,e;
void readedges()
{
	int i,x,y;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		matrix[x][y]=1;	
		matrix[y][x]=1;	
	}
	
}
bool isbipartite(int src)
{
	int colour[100];
	memset(colour,-1,sizeof colour);
	queue<int>q;
	q.push(src);
	colour[src]=1;
	while(!q.empty())
	{int p=q.front();
	q.pop();
	
	for(int i=1;i<=v;i++)
	{
		if(matrix[p][i]&&colour[i]==-1)
		{
			colour[i]=1-colour[p];
			q.push(i);
		}
		else if(matrix[p][i]&&colour[i]==colour[p])
		return false;
	}	
		
	}
	return true;
}
int main()
{
	scanf("%d%d",&v,&e);
	memset(matrix,0,sizeof matrix);
	readedges();
	if(isbipartite(1))
	printf("Yes\n");
	else
	printf("NO\n");
	return 0;
}
